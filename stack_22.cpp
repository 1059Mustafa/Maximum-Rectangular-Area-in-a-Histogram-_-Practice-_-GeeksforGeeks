void left_l(long long arr[],int n, int &left[])
{
    stack<pair<int,int>>s;
    for(int i=0;i<n;i++)
    {
        if(s.size()==0)
        {
            left[i]=-1;
        }
        else if(s.size()>0&&arr[i]>s.top().first)
        {
            left[i]=s.top().second;
        }
        else if(s.size()>0&&s.top().first>=arr[i])
        {
            while(s.size()>0&&s.top().first>=arr[i])
            {
                s.pop();
            }
            if(s.size()==0)
            {
                left[i]=-1;
            }
            else
            {
                left[i]=s.top().second;
            }
            
        }
        s.push(arr[i],i);
    }
}

void left_r(long long arr[],int n, long long &right)
{
    stack<pair<long long,long long>>s;
    for(int i=n-1;i>=0;i--)
    {
        if(s.size()==0)
        {
            right[i]=n;
        }
        else if(s.size()>0&&arr[i]>s.top().first)
        {
            right[i]=s.top().second;
        }
        else if(s.size()>0&&s.top().first>=arr[i])
        {
            while(s.size()>0&&s.top().first>=arr[i])
            {
                s.pop();
            }
            if(s.size()==0)
            {
                right[i]=n;
            }
            else
            {
                right[i]=s.top().second;
            }
            
        }
        s.push(arr[i],long long i);
    }
}

long long getMaxArea(long long arr[], int n)
{
    
    int left[n];
    int right[n];
    find_l(arr,n,left);
    find_r(arr,n,right);
    int width[n];
    long mx=0;
    for(int i=0;i<n;i++)
    {
        width[i]=right[i]-left[i]-1;
    }
    for(int i=0;i<n;i++)
    {
        arr[i]=arr[i]*width[i];
    }
    for(int i=0;i<n;i++)
    {
        mx=max(mx,arr[i]);
    }
    return mx;
}
