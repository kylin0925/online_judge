#include <stdio.h>
#include <string.h>

int check_no_opr(char tmp[]){
        if(strcmp(tmp,"HLT")==0 ||strcmp(tmp,"NOP")==0 ||
           strcmp(tmp,"RET")==0 || strcmp(tmp,"WAIT")==0) return 1;
        return 0;
}
int check_obj(char tmp[]){
        if(tmp[strlen(tmp)-1]=='-')return 0;
        return 1;
}
int match(char sym[],char obj[]){
        int len=strlen(obj);
        char tmp[1024];
        char *t;
        strcpy(tmp,obj);
        if(strstr(obj,sym)==NULL) return 0;
        return 1;
}
void replace(char add[],char obj[]){
        char tmp[1024];
        char *t;
        t=strtok(obj,",");
        while(t!=NULL){
                strcpy(tmp,t);
                t=strtok(NULL,",");
        }
        t=strtok(tmp,"-");
        strcpy(tmp,t);
        strcat(tmp,add);
        strcpy(obj,tmp);
}
int main(int argc, char* argv[])
{
        char buff[1024],tab[5][30];
        char symtab[1000][30];
        char add[1000][15];
        char cobj[1000][50];
        char tab2[5][50];
        char *tmp;
        int nolab,fnoopr,tcnt=0,symcnt=0,cobjcnt=0;
        freopen("u4in.txt","r",stdin);
        memset(buff,'\0',1024);
        while(gets(buff)!=NULL){
                nolab=0;
                tcnt=0;
                fnoopr=0;
                if(buff[0]=='\t') nolab=1;
                tmp=strtok(buff," \t");

                while(tmp!=NULL){
                        strcpy(tab[tcnt++],tmp);
                        tmp=strtok(NULL,"\t");
                }
                if(check_no_opr(tab[1-nolab])) fnoopr=1;
                if(strcmp(tab[1-nolab],"START")==0) continue;
                if(strcmp(tab[0],"END")==0) break;
                if(check_obj(tab[4-nolab-fnoopr])){
                        strcpy(cobj[cobjcnt++],tab[4-nolab-fnoopr]);
                }else if(strcmp(tab[1-nolab],"RESW")){
                        cobj[cobjcnt][0]='?';cobj[cobjcnt][1]=',';
                        strcat(cobj[cobjcnt],tab[2-nolab]);
                        strcat(cobj[cobjcnt],",\0");
                        strcat(cobj[cobjcnt],tab[4-nolab]);
                        cobjcnt++;
                }
                if(nolab==0){
                        strcpy(symtab[symcnt],tab[0]);
                        strcpy(add[symcnt++],tab[3-nolab-fnoopr]);
                }
                memset(buff,'\0',1024);
        }
        for(int i=1;i<symcnt;i++){
                for(int j=0;j<cobjcnt;j++){
                        if(cobj[j][0]=='?'){
                                if(match(symtab[i],cobj[j])){
                                        replace(add[i],cobj[j]);
                                }
                        }
                }
        }
        for(int i=0,j=0;i<cobjcnt;i++){
                printf("%s\n",cobj[i]);
        }
        return 0;
}
 