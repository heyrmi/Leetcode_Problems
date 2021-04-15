class Solution {
public:
    bool isValid(string st) {
        int n = st.length();                                        //find length
        
        if(n%2 !=0) return false;                                   //if odd no of inputs in st return false
        
        stack<int> s;                                               //define stack 
        for(auto it : st){                                          //iterate over each element
            if(it == '(' || it == '{' || it == '[')                 //push whatever you get
                s.push(it);
            else if(it == ')' && !s.empty() && s.top() == '(')      //if ( is found pop )
                s.pop();
            else if(it == '}' && !s.empty() && s.top() == '{')      //if { is found pop }     
                s.pop();
            else if(it == ']' && !s.empty() && s.top() == '[')      //if [ is found pop ]
                s.pop();
        }
        
        return s.empty();                                           //if the stack is empty then true if not then false
    }
};