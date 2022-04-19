#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct dir{
    char dname[20];
    struct dir *dnext;
    struct dir *dadj;
    struct file *fadj;
}*root;

struct file{
    char fname[20];
    struct file *fnext;
};


void add_dir(){
    int ans,flag,num;
    char dn[10];
    struct dir *current=root;
    while(1){
        flag=0;
        printf("\nCurrent directory is %s",current->dname);
        printf("\nAdd directory under %s?(1 for YES)",current->dname);
        scanf("%d",&ans);
        if(ans==1){
            printf("\nEnter number of directories: ");
            scanf("%d",&num);
            struct dir *curr;
            for(int i=0;i<num;i++){
                curr=current;
		        struct dir *temp=(struct dir*)malloc(sizeof(struct dir));
		        printf("\nEnter the directory name: ");
		        scanf("%s",temp->dname);
		        temp->dnext=NULL;
		        temp->dadj=NULL;
		        temp->fadj=NULL;
		        if(curr->dadj==NULL){
		            printf("Added %s under %s\n",temp->dname,current->dname);
		            curr->dadj=temp;
		        }else{
		            curr=curr->dadj;
		            while(curr->dnext!=NULL)
		                curr=curr->dnext;
		            curr->dnext=temp;
		            printf("Added %s under %s\n",temp->dname,current->dname);
		        }
            }
            current=curr;
            break;
        }else{
            if(current->dadj==NULL){
                printf("\nNo subdirectories present");
                return;
            }
            printf("\nDirectories under %s\n",current->dname);
            struct dir *p=current->dadj;
            while(p!=NULL){
                printf("%s    ",p->dname);
                p=p->dnext;
            }
            printf("\nEnter directory: ");
            scanf("%s",dn);
            struct dir *q=current->dadj;
            while(q!=NULL){
                if(strcmp(q->dname,dn)==0){
                    flag=1;
                    current=q;
                    break;
                }else{
                    q=q->dnext;
                }
            }
            if(flag==0){
                printf("\nDirectory does not exist");
                return;
            }
        }
    }
}


void add_file(){
    int ans,flag,num;
    char fn[10];
    struct dir *current=root;
    while(1){
        flag=0;
        printf("\nCurrent directory is %s",current->dname);
        printf("\nAdd file under %s?(1 for YES)",current->dname);
        scanf("%d",&ans);
        if(ans==1){
            printf("\nEnter number of files: ");
            scanf("%d",&num);
            for(int i=0;i<num;i++){
		        struct file *temp=(struct file*)malloc(sizeof(struct file));
		        printf("\nEnter the file name: ");
		        scanf("%s",temp->fname);
		        temp->fnext=NULL;
		        if(current->fadj==NULL){
		            current->fadj=temp;
		            printf("Added %s under %s\n",temp->fname,current->dname);
		        }else{
		            struct file *curr=current->fadj;
		            while(curr->fnext!=NULL)
		                curr=curr->fnext;
		            curr->fnext=temp;
		            printf("Added %s under %s\n",temp->fname,current->dname);
		        }
            }
            break;
        }else{
            if(current->dadj==NULL){
                printf("\nNo subdirectories present");
                return;
            }
            printf("\nDirectories under %s\n",current->dname);
            struct dir *p=current->dadj;
            while(p!=NULL){
                printf("%s    ",p->dname);
                p=p->dnext;
            }
            printf("\nEnter directory: ");
            scanf("%s",fn);
            struct dir *q=current->dadj;
            while(q!=NULL){
                if(strcmp(q->dname,fn)==0){
                    flag=1;
                    current=q;
                    break;
                }else{
                    q=q->dnext;
                }
            }
            if(flag==0){
                printf("\nDirectory does not exist");
                return;
            }
        }
    }
}


void del_file(){
    int ans,flag,dflag;
    char fn[10];
    struct dir *current=root;
    struct file *p,*rem;
    while(1){
        flag=0;
        dflag=0;
        printf("\nFiles under %s\n",current->dname);
        p=current->fadj;
        if(p==NULL){
            printf("\nNo files under this directory");
            goto deldir;
        }
        while(p!=NULL){
            printf("%s    ",p->fname);
            p=p->fnext;
        }
        printf("\nDelete file?(1 for YES)");
        scanf("%d",&ans);
        if(ans==1){
            printf("\nEnter the file name: ");
            scanf("%s",fn);
            p=current->fadj;
            if(strcmp(p->fname,fn)==0){
                current->fadj=p->fnext;
                free(p);
                flag=1;
            }else{
                while(p->fnext!=NULL){
                    if(strcmp(p->fnext->fname,fn)==0){
                        rem=p->fnext;
                        p->fnext=rem->fnext;
                        free(rem);
                        flag=1;
                        break;
                    }
                    p=p->fnext;
                }
            }
            if(flag==0){
                printf("\nFile not present");
                return;
            }
            break;
        }else{
            deldir:
            if(current->dadj==NULL){
                printf("\nNo subdirectories present");
                return;
            }
            printf("\nDirectories under %s\n",current->dname);
            struct dir *p=current->dadj;
            while(p!=NULL){
                printf("%s    ",p->dname);
                p=p->dnext;
            }
            printf("\nEnter directory: ");
            scanf("%s",fn);
            struct dir *q=current->dadj;
            while(q!=NULL){
                if(strcmp(q->dname,fn)==0){
                    dflag=1;
                    current=q;
                    break;
                }else{
                    q=q->dnext;
                }
            }
            if(dflag==0){
                printf("\nDirectory does not exist");
                return;
            }
        }
    }
}


void del_sub(struct dir *p,struct dir *q){
    if(q->dnext!=NULL)
        del_sub(q,q->dnext);
    if(q->dadj!=NULL)
        del_sub(q,q->dadj);
    if(q!=NULL){
        if(p->dadj==q)
            p->dadj=NULL;
        else
            p->dnext=NULL;
        struct dir *rem=q;
        struct file *f=q->fadj;
        struct file *r;
        while(f!=NULL){
            r=f;
            f=f->fnext;
            q->fadj=f;
            printf("\nDeleted file %s",r->fname);
            free(r);
        }
        printf("\nDeleted directory %s",rem->dname);
        free(rem);
    }
}

void del_dir(){
    struct dir *current=root;
    struct dir *sub;
    char dn[20];
    int ch,flag;
    while(1){
        flag=0;
        printf("\nCurernt directory is: ");
        printf("%s",current->dname); 
        sub=current->dadj;
        printf("\nDirectories under %s\n",current->dname);
        while(sub!=NULL){
            printf("%s   ",sub->dname);
            sub=sub->dnext;
        }
        printf("\nEnter directory?(1 for YES) ");
        scanf("%d",&ch);
        if(ch==1){
            printf("\nEnter directory name: ");
            scanf("%s",dn);
            sub=current->dadj;
            while(sub!=NULL){
                if(strcmp(sub->dname,dn)==0){
                    current=sub;
                    flag=1;
                    break;
                }
                sub=sub->dnext;
            }
            if(flag==0){
                printf("\nDirectory not present");
                break;
            }
        }else{
            printf("\nEnter the directory to be deleted: ");
            scanf("%s",dn);
            struct dir *p=current->dadj;
            while(p!=NULL){
                if(strcmp(p->dname,dn)==0){
                    if(p->dadj!=NULL)
                        del_sub(p,p->dadj);
                    struct file *f=p->fadj;
                    while(f!=NULL){
                        struct file *r=f;
                        f=f->fnext;
                        p->fadj=f;
                        printf("\nDeleted file %s",r->fname);
                        free(r);
                    }
                    struct dir *rem=p;
                    p=p->dnext;
                    current->dadj=p;
                    printf("\nDeleted directory %s",rem->dname);
                    free(rem);
                    break;
                }
                p=p->dnext;
            }
            break;
        }
    }
}


void dispf(struct file *f,int count){
	if(f==NULL)
		return;
	else{
		printf("\n");
		int cnt=count;
		while(cnt){
			printf("\t");
			cnt--;
		}
		printf("%s(f)",f->fname);
		dispf(f->fnext,count);
	}
}

void disp(struct dir  *p,int count){
	if(p==NULL)
		return;
	else{
		printf("\n");
		int cnt=count;
		while(cnt){
			printf("\t");	
			cnt--;	
		}
		printf("%s(d)",p->dname);
		disp(p->dadj,count+1);
		dispf(p->fadj,count+1);
		disp(p->dnext,count);
	}
}


void main(){
    int op;
    char d[20],path[50];
    root=(struct dir*)malloc(sizeof(struct dir));
    strcpy(root->dname,"/");
    root->dnext=NULL;
    root->dadj=NULL;
    root->fadj=NULL;
    while(1){
        printf("\nSelect operation:\n");
        printf("1.Add directory\n2.Add file\n3.Delete directory\n4.Delete file\n5.Traverse\n6.Exit");
        printf("\nEnter your option: ");
        scanf("%d",&op);
        switch(op){
            case 1: add_dir();
                    break;
            case 2: add_file();
                    break;
            case 3: del_dir();
                    break; 
            case 4: del_file();
                    break; 
            case 5: disp(root,0);
                    break; 
            case 6: exit(0);
        }
    }
}