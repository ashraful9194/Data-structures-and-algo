int modIverse(int x,int y)
{
    int res = 1;

    x = x % p;
    while (y > 0) {
        if (y & 1)
            {
                res = (res * x) % p;
                --y;
                if(y==0) break;
            }

        y = y >> 1;
        x = (x * x) % p;
    }
    return res;
}
///a^-1%p=a^p-2......
///This works only for mod prime.....
///a and mod must be co-prime.....
