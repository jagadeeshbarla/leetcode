//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

class Node{
public:
    int val;
    Node *next;
    Node(int num){
        val=num;
        next=NULL;
    }
};


// } Driver Code Ends
//User function Template for C++

/*

class Node{
public:
    int val;
    Node *next;
    Node(int num){
        val=num;
        next=NULL;
    }
};

*/

class Solution{
public:
    bool check(int n)
    {
        int flag=1;
        for (int i = 2; i <= sqrt(n); i++) 
        {
            if (n % i == 0)
            {
                flag = 0;
                break;
            }
        }
  
    if (n <= 1)
        flag = 0;
  
    if (flag == 1) {
        return false;
    }
    else {
        return true;
    }

    
    }
    Node *primeList(Node *head){
        Node *temp=head;
        while(temp)
        {
            if(check(temp->val))
            {
                //cout<<temp->val<<"  ";
                int i=0;
                while(1)
                {
                    if(!check(temp->val-i))
                    {
                        temp->val-=i;
                        break;
                    }
                    else if(!check(temp->val+i))
                    {
                        temp->val+=i;
                        break;
                    }
                    i+=1;
                }
            }
            temp=temp->next;
        }
        return head;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        Node *head,*tail;
        int num;
        cin>>num;
        head=tail=new Node(num);
        for(int i=0;i<n-1;i++){
            int num;
            cin>>num;
            tail->next=new Node(num);
            tail=tail->next;
        }
        Solution ob;
        Node *temp=ob.primeList(head);
        while(temp!=NULL){
            cout<<temp->val<<" ";
            temp=temp->next;
        }
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends