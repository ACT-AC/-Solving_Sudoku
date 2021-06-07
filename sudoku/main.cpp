#include <iostream>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
unsigned int question[9][9]={{0,6,0, 0,0,0, 0,0,0},
							 {0,0,0, 5,0,0, 0,7,0},
							 {0,0,0, 0,0,9, 2,0,3},
							 
							 {0,0,0, 0,0,2, 0,4,0},
							 {0,5,0, 4,0,0, 8,0,9},
							 {8,0,0, 3,0,0, 6,0,0},
							 
							 {6,0,1, 9,0,0, 0,0,5},
							 {3,7,2, 0,0,4, 0,0,0},
							 {0,0,0, 0,3,0, 0,0,0}};
/*unsigned int question[9][9]={{0,0,0, 2,1,3, 0,0,9},
							 {0,3,0, 4,0,7, 1,0,0},
							 {8,0,0, 0,5,0, 0,0,0},
							 
							 {1,0,6, 0,0,8, 2,0,7},
							 {0,0,0, 0,0,0, 0,0,0},
							 {2,0,3, 9,0,0, 8,0,1},
							 
							 {0,0,0, 0,4,0, 0,0,8},
							 {0,0,9, 8,0,2, 0,4,0},
							 {3,0,0, 7,9,5, 0,0,0}};*/

unsigned int number_all [9][9];
unsigned int number [9][9];
unsigned int answer [9][9];
unsigned int ok_num=0,preok_num=1,question_num;
int num_x=0,num_y=0;	
int state=0; 
						 
int check (int number);
void number_check(void);
void onlynumber_x(void);
void onlynumber_y(void);
void onlynumber_o(void);
void next_xy(void);
void last_xy(void);
void display(void);
void ansplus(void);


int main(int argc, char** argv) {
	//setup
	int x,y;
	
	for(x=0;x<9;x++){
		for(y=0;y<9;y++){
			if(question[x][y]>0){
				answer[x][y] = question[x][y];
				question_num++;
			}
		}
	}
	x = 0;
	y = 0;
	int test;
	//display();
	//printf("done %d\n",question_num);
	//main
	
	
		
//	number_check();
//	printf("\n\n");
//	printf("done %d %d\n",ok_num,preok_num);
//	display();
	number_check();
	display();
	number_check();
	display();
	//display();
	while(ok_num != preok_num){
		
		preok_num = ok_num;
		
		onlynumber_o();
		number_check();
		onlynumber_x();
		number_check();
		onlynumber_y();
		number_check();
		
		
	}

	printf("\n\n");
	display();
	printf("done %d\n",ok_num - question_num);
	return 0;
}
//---------------------------------------------------------------------------------------------------------------
void onlynumber_x(void){
	int same_num=0; 
	int x=0,y,A=1,y_ok;
	for(int i=1;i<10;i++){
	    for(x=0;x<9;x++){
			y_start:
			same_num = 0;
			for(y=0;y<9;y++){
				if(number[x][y] == 0){  //如果掃描到的坐標裏沒有數字 
					if(number_all[x][y] == i){ //如過坐標裏可填入的數字為i
						i++;
						goto y_start;
					}
				}	
				else{
					for(int j=0;j<number[x][y];j++){ //xy裏可填數字量 
						A = 1;
						for(int k=0;k<j;k++)
							A = A * 10;
						if((number_all[x][y]/(A))%10 == i){							
							y_ok = y;
							same_num++;
						}
				
					}
				}	
			}
			if(same_num==1){
				number_all[x][y_ok] = 0;
				number[x][y_ok] = 0;
				answer[x][y_ok] = i;
				ok_num++;
			}
		}
	}	
}
//---------------------------------------------------------------------------------------------------------------
void onlynumber_y(void){
	int same_num=0; 
	int x,y=0,A=1,x_ok;
	for(int i=1;i<10;i++){
	    for(y=0;y<9;y++){
			x_start:
			same_num = 0;
			for(x=0;x<9;x++){
				if(number[x][y] == 0){  //如果掃描到的坐標裏沒有數字 
					if(number_all[x][y] == i){ //如過坐標裏可填入的數字為i
						i++;
						goto x_start;
					}
				}	
				else{
					for(int j=0;j<number[x][y];j++){ //xy裏可填數字量 
						A = 1;
						for(int k=0;k<j;k++)
							A = A * 10;
						if((number_all[x][y]/(A))%10 == i){	
							x_ok = x;
							same_num++;
						}
			
					}
				}	
			}
			if(same_num==1){
				number_all[x_ok][y] = 0;
				number[x_ok][y] = 0;
				answer[x_ok][y] = i;
				ok_num++;
			}
		}
	}	
}
//---------------------------------------------------------------------------------------------------------------
void onlynumber_o(void){
	int same_num=0; 
	int x=0,y,A=1,x_ok,y_ok; //
	for(int num=1;num<10;num++){
		for(int i=0;i<3;i++){
			for(int j=0;j<3;j++){
				start:
				same_num = 0;
				for(x=i*3;x<i*3+3;x++){
					for(y=j*3;y<j*3+3;y++){
						if(number[x][y] == 0){  //如果掃描到的坐標裏沒有數字 
							if(number_all[x][y] == num){ //如過坐標裏可填入的數字為i
								num++;
								goto start;
							}
						}	
						else{
							for(int g=0;g<number[x][y];g++){ //xy裏可填數字量 
								//printf("j%d %d%d\t",j,x,y);
								//printf("test1\t");
								A = 1;
								for(int k=0;k<j;k++){
									A = A * 10;
									//printf("k%d",k);
								}
								//printf("test2\t");
								if((number_all[x][y]/(A))%10 == i){
									x_ok = x;
									y_ok = y;
									same_num++;
									//printf("s%d",same_num);
								}		
							}
						}
					}
				}
				if(same_num==1){
					number_all[x_ok][y_ok] = 0;
					number[x_ok][y_ok] = 0;
					answer[x_ok][y_ok] = i;
					ok_num++;
				}
				
			}
		}
	}
}
//---------------------------------------------------------------------------------------------------------------
void number_check(void){
	int x,y;
	int ok,preok_num_1;
	
	while(ok_num != preok_num_1){
		preok_num_1 = ok_num;
		ok = 0;
		ok_num = 0;
		for(int i=0;i<9;i++){
			for(int j=0;j<9;j++){
				number_all[i][j] = 0;
				number[i][j] = 0;
			}
		}
		for(int i=0;i<81;i++){
			if(answer[num_x][num_y]>0){
				ok_num++;
				next_xy();
			}
			else{
				for(int j=1;j<10;j++){
					ok = check(j);
					if(ok == 1){
						number_all[num_x][num_y] = number_all[num_x][num_y] * 10 + j;
						number [num_x][num_y]++;
					}
				}
				if(number[num_x][num_y] == 1){
					answer[num_x][num_y] = number_all[num_x][num_y];
					ok_num++;
				}
				next_xy();
			}
		}
	}
}
//---------------------------------------------------------------------------------------------------------------
void ansplus(void){
	answer[num_x][num_y]++;
	if(answer[num_x][num_y]>9){
		answer[num_x][num_y] = 0;
		last_xy();
		answer[num_x][num_y]++;
	}
		
}
//---------------------------------------------------------------------------------------------------------------
void next_xy(void){
	if(num_y<8) 		
		num_y++;
	else {
		num_x++;
		num_y=0;
	}
	if(num_x>8) 		
		num_x=0;
	
	//answer[num_x][num_y]++;
}
//---------------------------------------------------------------------------------------------------------------
void last_xy(void){
	
	if(num_y>0) {
		
		num_y-=1;
		//printf("y%d\n",num_y);
	}
	else {
		num_x-=1;
		num_y=8;
	}
	
	//answer[num_x][num_y]++;
	
}
//---------------------------------------------------------------------------------------------------------------
int check (int number){
	if (number>9)
		return 0;
	int x,y,i,j;
	for(y=0;y<9;y++){
		if(y==num_y){
			//y++;
			//break;
		}
		else{
			if(answer[num_x][y] == number){
				return 0;	
			}
		}				
	}
	for(x=0;x<9;x++){
		if(x==num_x){
			//x++;
			//break;
		}
		else{
			if(answer[x][num_y] == number){
				return 0;	
			}
		}
	}
	if(num_x<3) 	i=3;
	else if(num_x<6)i=6;
	else if(num_x<9)i=9;
	else state = 40;
	if(num_y<3) 	j=3;
	else if(num_y<6)j=6;
	else if(num_y<9)j=9;
	else state = 40;
	for(x=i-3;x<i;x++){
		for(y=j-3;y<j;y++){
			if(x==num_x & y==num_y){
			}
			else{
				if(answer[x][y] == number){
					return 0;	
				}
			}
				
		}
	}
	return 1;
}
//---------------------------------------------------------------------------------------------------------------
void display(void){
	for(int i=0;i<9;i++){
		for(int j=0;j<9;j++){
			printf("%d ",answer[i][j]);
			if(j%3==2)
				printf(" ");
		}		
		printf("\n");
		if(i%3==2)
			printf("\n");
	}
	for(int i=0;i<9;i++){
		for(int j=0;j<9;j++){
			printf("%8d %d",number_all[i][j],number[i][j]);
			if(j%3==2)
				printf(" ");	
			
		}
		printf("\n");
		if(i%3==2)
			printf("\n");
	}
	printf("done_test %d\n",ok_num);
}
