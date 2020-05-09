#include<bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> v,ans,frac;
    double x,prec,y1;
    int in,in1,y, sbit, exp, cnt,moved=0;
    cin >> x ;

    (x > 0) ? sbit = 0 : sbit = 1;  // if pos number sign bit = 0 else sign bit = 1 and x = abs[x], 
    x = abs(x);                   // cause you have to ignore the negative value to convert to binary

    in = in1 = x;                       // integer part in in vaiable
    prec = x - in;                // precision part in prec variable

    while(in!=0)                // converting int value to binary 
    {
        y = in%2;
        v.push_back(y);
        in /= 2 ;
    }
    reverse(v.begin(),v.end()); // converting done

    y1=prec;
    int flag = 0;

    for(int i=1; i<=100; i++) // ei jaygay joga khichuri pakaisi... but Dont touch, it works
    {
        y1 = y1*2;
        y = y1;
        if(in1 !=0) frac.push_back(y);
        else if( !flag && y==1) {
            moved = i;
            flag =1;
        }
        else if(flag) frac.push_back(y);
        y1-=y;
    }

    if(in1 != 0) moved = 1;

    exp = ( v.size() - moved ) + 127 ; // calculating power of 2 .. like 1.001000111 X 2^8, here exp = 8 +127

    while(exp!=0)       // converting exp value to binary 
    {
        y = exp%2;
        ans.push_back(y);
        exp /= 2 ;
    }
    if(in1 == 0) ans.push_back(0); // to full fill 8 bit of exp

    ans.push_back(sbit); // pushing the sign bit to the vector
    reverse(ans.begin(),ans.end()); // as I'm reversing the whole vector so we're gonna have the sign to at 0th postion

    for(int i=1;i<v.size();i++)  // 
        ans.push_back(v[i]);


    for(int i=0;i<frac.size();i++)
        ans.push_back(frac[i]);

    for(int i=0,j=1;i<32;i++,j++)
    {
        cout << ans[i] ;
        if(j==4) {cout << " ",j=0;}     // printing the answer in '4 bit then a space' format
    }
    cout << endl;
    return 0;    
}
//291.95
//0100 0011 1001 0001 1111 1001 1001 1010

//0.00017
//0011 1001 0011 0010 0100 0010 0000 0111