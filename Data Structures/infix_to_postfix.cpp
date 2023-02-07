#include<bits/stdc++.h>
using namespace std;

int precedence(char m){
  
  if(m == '^') 
    return 3; 
  else if(m == '*' || m == '/') 
    return 2; 
  else if(m == '+' || m == '-') 
    return 1;
  else;
    return 0;

}

void convert(string t){
  stack<char> s;
  int len = t.length();
  string ans;
  
  for(int i = 0; i < len; i++){ 
    if((t[i] >= 'a' && t[i] <= 'z') || (t[i] >= 'A' && t[i] <= 'Z')) 
        ans+=t[i]; 

    else if(t[i] == '(') 
        s.push('('); 
        
    else if(t[i] == ')'){ 
      while(s.top() != '('){
        char c = s.top(); 
        ans += c;
        s.pop();
      }
      if(s.top() == '(') 
      { 
        char c = s.top(); 
        s.pop(); 
      } 
    }
    else{ 
      while(s.empty()==false && precedence(t[i]) <= precedence(s.top())){ 
        char c = s.top();
        ans += c; 
        s.pop(); 
      }
      s.push(t[i]); 
    }
  }

  while(s.empty() == false){ 
    char c = s.top();
    ans += c;
    s.pop();
  } 
  
  cout << "Postfix Expression: " << ans << endl; 
}

int main(){
  string s;
  cout<<"Enter Expression: ";
  cin>>s;
  // string s = "a+b*c"; 
  
  convert(s);
  return 0; 
} 