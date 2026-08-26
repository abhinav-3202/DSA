class Solution {
public:
    string rev(int count){
        string temp;
        while(count>0){
            temp += count%10 + '0';
            count=count/10;
        }
        reverse(temp.begin(),temp.end());
        return temp;
    }
    void check(string & s,vector<char>& chars,int& count,char& prev,int i){
        if(count<10){
            s+=prev;
            if(count!=1){
                s+=count+'0';
            }
            prev=chars[i];
            count=1;
        }
        else{
            s+=prev;
            string ss=rev(count);
            int j=0;
            while(j<ss.size()){
                s+= ss[j];
                j++;
            }
            count=1;
            prev=chars[i];
        }
        return ;
    }
    int compress(vector<char>& chars) {
        if(chars.size()==1) return 1;
        char prev=chars[0];
        int n=chars.size();
        string s;
        int count =1;
        for(int i=1;i<n;i++){
            if(i==n-1){
                if(chars[i]==prev){
                    count++;
                    check(s,chars,count,prev,i);
                }
                else{
                    check(s,chars,count,prev,i);
                    count=1;
                    check(s,chars,count,chars[i],i);
                }
            }
            else{
                if(chars[i]==prev){
                    count++;
                }
                else {
                    check(s,chars,count,prev,i);
                }
            }
        }
        int m=s.size();
        for(int i=0;i<m;i++){
            chars[i]=s[i];
        }
        return s.size();
    }
};