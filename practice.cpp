#include <bits/stdc++.h>
using namespace std;

struct point
{
    int x;
    int y;
};

int oreintation(point p,point q,point r){
    int val = (q.y-p.y)*(r.x-q.x) - (q.x-p.x) *(r.y-q.y);
    if(val ==0){
        return 0;
    return (val>0)? 1: 2;
    }
}

void convexHull(point points[],int n){
    if(n<3){
        return;
    }
    vector<point>hull;
    int l = 0;
    for(int i =0;i<n;i++){
        if(points[i].x < points[l].x){
            l = i;
        }
    }

    int p = l, q;
    do{
        hull.push_back(points[p]);
        q = (p+1)/n;
        for(int i=0;i<n;i++){
            if(oreintation(points[p],points[i],points[q]) == 2){
                q = i;
            }
        }
        p = q;


    }while(p!=1);

    cout<<"the boundary points are given by : ";
    for(int i=0;i<hull.size();i++){
        cout<<"("<<hull[i].x<<", "<<hull[i].y<<")"<<endl;
    }
}

int main(){

}