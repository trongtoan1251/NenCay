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
int soCanhConLai(canh* a, int soCanh){
	int count=0;
	for(int i=0;i<soCanh;i++){
		if(a[i].x>0&&a[i].y>0){
			count++;
		}
	}
	return count;
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
	int i=1;
	printf("prufer code\n");
	while(soCanhConLai(q,soCanh)){
		if(p[i]==1){
			for(int j=0;j<soCanh;j++){
				if(q[j].x==i){
					printf("%d ",q[j].y);
					p[q[j].x]--;
					p[q[j].y]--;
					q[j].x=-1;
					q[j].y=-1;
					i=0;
					break;
				}else if(q[j].y==i){
					printf("%d ",q[j].x);
					p[q[j].x]--;
					p[q[j].y]--;
					q[j].x=-1;
					q[j].y=-1;
					i=0;
					break;
				}
			}
		}
		i++;
	}
	free(q);
	free(p);
	return 0;
}
