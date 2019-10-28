#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
typedef struct{
	int x;
	int y;
} canh;
canh taoCanh(int x,int y){
	canh a;
	a.x=x;
	a.y=y;
	return a;
}
int main(){
	int soCanh;
	scanf("%d",&soCanh);
	int soDinh=soCanh+1;
	int* p;
	canh* q;
	p=(int*)calloc(soDinh,sizeof(int));  //mang p luu tru bac cua dinh
	q=(canh*)malloc(sizeof(canh)*soCanh);  //mang q luu tru cac canh trong cay
	for(int i=0;i<soCanh;i++){
		int x,y;
		scanf("%d%d",&x,&y);
		p[x]++;
		p[y]++;
		q[i]=taoCanh(x,y);
	}
	for(int i=1;i<soDinh;i++){
		if(p[i]==1){
			for(int j=0;j<soCanh;j++){
				if(q[j].x==i){
					printf("%d ",q[j].y);
					p[q[j].x]--;
					p[q[j].y]--;
					q[j].x=-1;
					q[j].y=-1;
				}else if(q[j].y==i){
					printf("%d ",q[j].x);
					p[q[j].x]--;
					p[q[j].y]--;
					q[j].x=-1;
					q[j].y=-1;
				}
			}
		}
	}
	free(q);
	free(p);
	return 0;
}
