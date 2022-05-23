#include<bits/stdc++.h>
using namespace std;

//key={2,0,1,3}
//mssg="We will die"

string encryption(string mssg,vector<int> key){
    int col=key.size();
    int row=mssg.length()/col;
    if(mssg.length() % col)
        row++;
    char mat[row][col];
    int k=0;
    map<int,int>mp;
    for(int i=0;i<key.size();i++){
        mp[key[i]]=i;
    }
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            if(k<mssg.length())
                mat[i][j]=mssg[k];
            else
                mat[i][j]='$';
            k++;
        }
    }
    string ans="";
    for(auto x: mp){
        for(int i=0;i<row;i++)
            ans.push_back(mat[i][x.second]);
    }
    
    return ans;
}
string decryption(string txt,vector<int> key){
    int col=key.size();
    int row=txt.length()/col;
    char mat[row][col];
    int k=0;
    for(int i=0;i<col;i++){
        for(int j=0;j<row;j++){
            mat[j][i]=txt[k];
            k++;
        }
    }
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++)
            cout<<mat[i][j]<<" ";
            cout<<endl;
    }
    map<int,int> mp;
    for(int i=0;i<key.size();i++){
        mp[i]=key[i];
    }
    string ans="";
    char mat2[row][col];
    for(auto x:mp){
        for(int i=0;i<row;i++){
            mat2[i][x.first]=mat[i][x.second];
        }
    }
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            ans.push_back(mat2[i][j]);
    }
    }
    return ans;
}
int main(){
    vector<int> key={2,0,1,3};
    string mssg="We will die";
    string ans=encryption(mssg,key);
    cout<<ans<<endl;
    string ans2=decryption(ans,key);
    cout<<ans2<<endl;

}



// 3 1 2 4
// 1 2 3 4
// w e   w
// i l l 
// d i e $

// 3->1 1->2 1->3
// 1->2 2->3 2->1
// 2->3 3->1 3->2
// 4->4 4->4 4->4
// encrytped->eli leWidw $
//  1 2 3 4
// e   W w   // W
// l l i 
// i e d $