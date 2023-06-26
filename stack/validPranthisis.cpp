    bool ispar(string x)
    {
        // Your code here
        stack<char> stack;
        for(auto i : x){
            if(i=='{' || i=='(' || i=='[') stack.push(i);
            else{
                if(stack.empty()) return false;
                else if(!stack.empty()){
                    if(i==')' && stack.top() == '(') stack.pop();
                    else if(i=='}' && stack.top() == '{') stack.pop();
                    else if(i==']' && stack.top() == '[') stack.pop();
                    else return false;
                }
            }
        }
        if(!stack.empty()) return false;
        return true;
    }