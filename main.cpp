
#include <cstdlib>
#include <iostream>
#include <math.h>
using namespace std;



struct Vector{
    int x;
    int y;
};

struct Diagonal{
    Vector v1;
    Vector v2;
};

int *array=new int[64];
int n=64;
int z=8;
int matrix[8][8];

Vector subVector(Vector v1,Vector v2){
    Vector sub;
    sub.x=v2.x-v1.x;
    sub.y=v2.y-v1.y;
    return sub;
}
Vector dirVector(Vector v1,Vector v2){
    Vector sub;
    sub.x=v2.x-v1.x;
    sub.y=v2.y-v1.y;
    int x=sub.x;
    int y=sub.y;
    Vector dir;
    if(x<0){
        dir.x=-x;
    }else{
        dir.x=x;
    }
    if(y<0){
        dir.y=-y;
    }else{
        dir.y=y;
    }
    return dir;
}

void fillArray(int *a,int n){
    for(int i=0;i<n;++i){
        a[i]=i;
        cout<<a[i]<<" ";
    }
}
void showMatrix(int m[8][8], int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            
            if(m[i][j]<10){
                cout<<" ";
            }
            cout<<m[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
    
}
void createMatrix(int m[8][8], int n ){
    //m=new int*[n];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            m[i][j]=0;
            cout<<m[i][j]<<" ";
        }
        cout<<endl;
        
    }
    cout<<endl;
    cout<<endl;
    cout<<endl;
}

void setElem(int m[8][8],int x,int y,int val){
    m[y][x]=val;
}

void rotateMatrix(int matr[8][8],int n){
    /*for(int i=0;i<n;i++)
    for(int j=0;j<n;j++)
    cin>>matr[i][j];*/
    
    int tmp;
    for(int i=0;i<n/2;i++)
    {
        for(int j=i;j<n-1-i;j++)
        {
            tmp = matr[i][j];
            matr[i][j] = matr[n-j-1][i];
            matr[n-j-1][i] = matr[n-i-1][n-j-1];
            matr[n-i-1][n-j-1] = matr[j][n-i-1];
            matr[j][n-i-1] = tmp;
        }
    }
}

void buildMatrix(int m[8][8],Vector startCoord,Vector vdx1,Vector vdx2,int type){
    int index=0;
    int dx1=vdx1.x;
    int dy1=vdx1.y;
    
    int dx2=vdx2.x;
    int dy2=vdx2.y;
    int dx;
    int dy;
    if(type==0){
       dx=dx2;
       dy=dx2;
    }else{
       dx=dx1;
       dy=dx1;
    }

    
    int coordX=startCoord.x;
    int coordY=startCoord.y;
    while(index<64){
        
        setElem(m,coordX,coordY,array[index]);
        if(index==63)break;
        index++;
        
        if(coordX+dx<0){
            coordY++;
            dx=dx1;
            dy=dy1;
            setElem(m,coordX,coordY,array[index]);
            if(index==63)break;
            index++;
        }
        
        if(coordY+dy>7){
            coordX--;
            dx=dx2;
            dy=dy2;
            setElem(m,coordX,coordY,array[index]);
            if(index==63)break;
            index++;
        }
        
        if(coordX+dx>7){
            coordY++;
            dx=dx2;
            dy=dy2;
            setElem(m,coordX,coordY,array[index]);
            if(index==63)break;
            index++;
        }
        if(coordY+dy<0){
            coordX--;
            dx=dx1;
            dy=dy1;
            setElem(m,coordX,coordY,array[index]);
            if(index==63)break;
            index++;
        }
        
        coordX+=dx;
        coordY+=dy;
        
        
    }
}

int main(int argc, char** argv) {
    fillArray(array,n);
    
    createMatrix(matrix,z);
    
    Vector startPos,vdx1,vdx2;
    
    startPos.x=7;
    startPos.y=0;
    vdx1.x=1;
    vdx1.y=1;
    vdx2.x=-1;
    vdx2.y=-1;
    
    buildMatrix(matrix,startPos,vdx1,vdx2,1);
    showMatrix(matrix,z);
    rotateMatrix(matrix,8);
    showMatrix(matrix,z);
    rotateMatrix(matrix,8);
    showMatrix(matrix,z);
    rotateMatrix(matrix,8);
    showMatrix(matrix,z);
    
    buildMatrix(matrix,startPos,vdx1,vdx2,1);
    showMatrix(matrix,z);
    rotateMatrix(matrix,8);
    showMatrix(matrix,z);
    rotateMatrix(matrix,8);
    showMatrix(matrix,z);
    rotateMatrix(matrix,8);
    showMatrix(matrix,z);
   
    return 0;
}

