#include<bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> v,ans,frac;
    double x,prec,y1;
    int in,in1,y, sbit, exp, cnt,moved=0;
    cin >> x ; // 9.3

    (x > 0) ? sbit = 0 : sbit = 1;     // if pos number sign bit = 0 else sign bit = 1 and x = abs[x],
    x = abs(x);                           // cause you have to ignore the negative value to convert to binary

    in = in1 = x;                       // integer part in 'in' vaiable
    prec = x - in;                        // precision part in prec variable

    while(in!=0)                    // converting int value to binary 
    {
        y = in%2; 
        v.push_back(y); 
        in /= 2 ; 
    }
    reverse(v.begin(),v.end()); // converting done

    // 9 - 1001 ---> 3 + 127 --> binary 

    y1=prec;
    int flag = 0;

    for(int i=1; i<=100; i++) // fraction to binary and keeping the track where i've got the first one 
    {
        y1 = y1*2;
        y = y1;

        if( !flag && y==1) { // and keeping the track where i've got the first one 
            moved = i;
            flag =1;
        }

        frac.push_back(y);
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

    for(int i=1;i<v.size();i++)  // sign bit and exp r pore integer part er binary push kortesi
        ans.push_back(v[i]);

    int frac_start = 0;
    if(in1==0) frac_start = moved;
    for(int i=frac_start;i<frac.size();i++) // ekdm last e fraction er binary push kortesi
        ans.push_back(frac[i]);

    for(int i=0,j=1;i<32;i++,j++)
    {
        cout << ans[i] ;
        if(j==4) {cout << " ",j=0;}     // printing the answer in '4 bit then a space' format
    }
    cout << endl;
    return 0;    
}
//test case 

//291.95
//0100 0011 1001 0001 1111 1001 1001 1010

//0.00017
//0011 1001 0011 0010 0100 0010 0000 0111


// <signbit> <expo 8 bit> <decimal bit>
// 0 11001011 001 
//0.3