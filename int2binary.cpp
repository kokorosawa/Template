string toBinary(int n,int len)
{   
    string r;
    while (n != 0){
        r += ( n % 2 == 0 ? "0" : "1" );
        n /= 2;
    }
    for (int i = r.size(); i < len ; i++)
    {
        r.push_back('0');
    }
    reverse(r.begin(),r.end());
    return r;
}
