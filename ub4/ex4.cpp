#include <iostream>

//Teil a
int search(int *a, int c, int x, int l, int r)
{
    int len = 9;
    int t, mt;
    // Nichts gefunden
    if (r - l < 0)
        return -1;
    t = (r + l) / 2;
    // die "wirkliche" (geshiftete) Position des mittleren Elements
    mt = (t + c) % len;
    if (a[mt] == x)
        return mt;
    if (a[mt] < x)
        return search(a, c, x, t + 1, r);
    else
        return search(a, c, x, l, t - 1);
}

int search(int *a, int c, int x)
{
    int n = 9;
    return search(a, c, x, 0, n - 1);
}
// Teil b
int getShift(int *a, int n)
{
    // Initialisiere
    int l = 0;
    int r = n - 1;
    int idx = 0;
    while (l <= r)
    {
        // Betrachte das mittlere Element
        // Wenn es kleiner als das bisherige Minimum ist, dann aktualisiere idx
        int t = (r + l) / 2;
        if (a[t] < a[idx])
            idx = t;
        // Falls a[r] > a[t] dann sind alle a[i] > a[t] fuer t <= i <= r
        // also kann das Minimum nur im Teilarray [a[l], ..., a[t]] sein
        // Da wir a[t] schon gesehen haben, reicht es in [a[l], ..., a[t−1]] zu suchen
        if (a[r] > a[t])
            r = t - 1;
        // Sonst ist das Minimum im Teilarray [a[t], ..., a[r]]
        // Da wir a[t] schon gesehen haben, reicht es in [a[t+1], ..., a[r]] zu suchen
        else
            l = t + 1;
    }
    return idx;
}

int main()
{
   int a[] = {23,25,36,1,4,8,12,15,18};
   int a_size = 9;
   int x_search = 4;
   int get_index_it = search(a, 3, x_search);
   if (get_index_it==-1) 
        std::cout<<"not found"<<"\n";
   else {
        std::cout<<"found at "<<get_index_it<<"\n";
   }
   int shift = getShift(a,9);
   std::cout<<"0 is shiffted to index "<<shift<<"\n";
   
   return 0;

}