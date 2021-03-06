#include<bits/stdc++.h>

using namespace std;

struct process{
                int id;
                int AT;
                int BT;
                int CT;
                int TAT;
                int WT;
                bool visited;
                };

bool cmp(struct process a, struct process b)
{
    int r1 = a.AT;
    int r2 = b.AT;

    if(r1 == r2)
        return a.id < b.id;
    else
        return r1 < r2;
}

void schedule(process p[], int n)
{
    sort(p, p+n, cmp);

    int time = p[0].AT;
    int done = 0;
    int i=0;

    cout<<"GANTT CHART : - \n\n|| ";

     while(done != n)
    {

        if(p[i+1].AT >= time+p[i].BT)
        {
            time++;
        }
        else
        {
            time += p[i].BT;
            cout<<"P"<<p[i].id<<" || ";

            p[i].CT = time;
            p[i].TAT = p[i].CT - p[i].AT;
            p[i].WT = p[i].TAT - p[i].BT;
            done++;
            i++;
        }

    }
     //Display:-
    cout<<"\n\nAfter scheduling : -\n\n";
    cout<<"Id     "<<"AT     "<<"BT     "<<" CT     "<<"TAT    "<<"WT     "<<endl;
    for(int i=0; i<n; i++)
    {
        cout<<p[i].id<<"      "<<p[i].AT<<"      "<<p[i].BT<<"       "<<p[i].CT<<"      "<<p[i].TAT<<"      "<<p[i].WT<<endl;
    }

    //average TAT
    double avgtat = 0;
    for(int i=0; i<n;i++)
    {
        avgtat = avgtat + p[i].TAT;
    }

    avgtat = (double) avgtat/n;

    //average WT
    double avgWT = 0;
    for(int i=0; i<n; i++)
    {
        avgWT = avgWT + p[i].WT;
    }
    avgWT = (double) avgWT/n;

    cout<<"\nAverage TAT is "<<avgtat<<endl;
    cout<<"\nAverage WT is "<<avgWT<<endl;

}


int main()
{
    cout<<"Enter number of processes you want : ";
    int n;
    cin>>n;
    process p[n] = {};

    for(int i=0;i<n;i++)
    {
        cout<<"\nEnter Process "<<i+1<<" details : - \n";
        cout<<"Process Id :  ";
        cin>>p[i].id;
        cout<<"Arrival time :  ";
        cin>>p[i].AT;
        cout<<"Burst time :  ";
        cin>>p[i].BT;
        p[i].visited = false;
    }
    //Display before scheduling
    cout<<"\nBefore Scheduling : - \n\n";
    cout<<"Id     "<<"AT     "<<"BT     "<<endl;
    for(int i=0; i<n; i++)
    {
        cout<<p[i].id<<"      "<<p[i].AT<<"      "<<p[i].BT<<endl;
    }

    schedule(p, n);


}


