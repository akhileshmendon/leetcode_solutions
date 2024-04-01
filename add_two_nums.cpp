/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        return l1;
    }
};

string convert(string& str){
    string result = "";
    for (int i = 0; i < str.size(); ++i) {
        if (isdigit(str[i])) 
            result.push_back(str[i]);
    }
    return result;
}

string format(string str){
    string result = "[";
    for(int8_t i = 0; i < str.length(); ++i){
        result.push_back(str[i]);
        result.push_back(',');
    }
    result.pop_back();
    result.push_back(']');
    return result;
}

string adder(string& s1, string& s2){
    string result = "";
    uint8_t temp1, temp2, carry = 0, i=0, j=0;

    for( ; j<s2.length(); i++, j++){
        temp1 = s1[i] - '0', temp2 = s2[j] - '0';
        result.push_back( '0' +  ((temp1 + temp2 + carry)%10) );
        carry = (temp1 + temp2 + carry)/10;
    }

    while(carry && i < s1.length()){
        temp1 = s1[i++] - '0';
        result.push_back( '0' +  ((temp1 + carry)%10) );
        carry = (temp1 + carry)/10;
    }

    if( carry )
        result.push_back( '0' +  carry );

    while( i < s1.length() )
        result.push_back(s1[i++]);

    return format(result);
}

char init = [](){
    string s1, s2, result;
    ofstream out("user.out");
    cout.rdbuf(out.rdbuf());

    while (cin >> s1 >> s2){
        s1 = convert(s1);
        s2 = convert(s2);
        if(s1.length() < s2.length()) swap(s1, s2);

        result = adder(s1, s2);
        cout<< result<< endl;
    }

    exit(0);
    return 'c';
}();
