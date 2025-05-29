#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<ctype.h>
#include "contact.h"
#include "file.h"
#include "populate.h"

void checknamecorrect(AddressBook *ptr1){//this function check name contain only alphabets or not
    char ch;                             //if it is not print invalid and again take input
    for(int i=0;ptr1->contacts[ptr1->contactCount].name[i]!='\0';i++){
        ch=ptr1->contacts[ptr1->contactCount].name[i];
        if(isalpha(ch)==0 && ch!=' '){
          printf("----------------------------------------------\n");
          printf("Please Enter Valid Name : ");
          getchar();
          scanf("%[^\n]",ptr1->contacts[ptr1->contactCount].name);
          checknamecorrect(ptr1);     
        }   
    }   
}
void checkmobilecorrect(AddressBook *ptr2){//this function check mobile number is validate or not
    char ch;
    for(int i=0;ptr2->contacts[ptr2->contactCount].phone[i]!='\0';i++){//to check number contain digit or not
        ch=ptr2->contacts[ptr2->contactCount].phone[i];
        if(!isdigit(ch)){
           printf("------------------------------------------------\n");
           printf("Please Enter Only Digit  Mobile Number :  ");
           getchar();
           scanf("%[^\n]",ptr2->contacts[ptr2->contactCount].phone);
           checkmobilecorrect(ptr2);
        }
    }
    if(strlen(ptr2->contacts[ptr2->contactCount].phone)!=10){//to check number contain only 10 digit or not
        printf("------------------------------------------------\n");
        printf("Please Enter 10 Digits  Mobile Number:  ");
        getchar();
        scanf("%[^\n]",ptr2->contacts[ptr2->contactCount].phone);
        checkmobilecorrect(ptr2);
    }
    for(int i=0;i<(ptr2->contactCount);i++){//to check number has already exist or not
        if(strcmp(ptr2->contacts[i].phone,ptr2->contacts[ptr2->contactCount].phone)==0){
            printf("------------------------------------------------\n");
            printf("   .....Aleardy Exits Phone Number.....\n\n");
            printf("Please Enter Valid Mobile Number : ");        
            getchar();
            scanf("%[^\n]",ptr2->contacts[ptr2->contactCount].phone);
            //printf("------------------------------------------------\n");  
            checkmobilecorrect(ptr2);
        }
    }
}
void checkemailcorrect(AddressBook *ptr3){ 
        if(strchr(ptr3->contacts[ptr3->contactCount].email,'@')==NULL){//this check @ character present or not
            printf("------------------------------------------------\n");
            printf("    ....'@' character is not present.... \n\n");
            printf("Please Enter Valid Email Id : ");
            getchar();
            scanf("%[^\n]",ptr3->contacts[ptr3->contactCount].email);
            //printf("------------------------------------------------\n");
            checkemailcorrect(ptr3);
        }
        else if(strstr(ptr3->contacts[ptr3->contactCount].email,".com")==NULL){//this check .com present or not
            printf("----------------------------------------------------------------\n");
            printf("   .........   '.com' Word is not present   ............\n\n");
            printf("Please Enter Valid Email Id : ");    
            getchar();
            scanf("%[^\n]",ptr3->contacts[ptr3->contactCount].email);
            //printf("----------------------------------------------------------------\n");
            checkemailcorrect(ptr3);
        }
        char* p=strstr(ptr3->contacts[ptr3->contactCount].email,"@");
        char* q=strstr(ptr3->contacts[ptr3->contactCount].email,".com");
        char* x=p-1;
        char* y=q-1;
        if(  !isalnum(*x) ||  !isalnum(*y) ){//this check @ and .com has previous character present or not
            printf("----------------------------------------------------------------\n");
            printf("  ..... Before '@' or else '.com' Character is not present .... \n\n");
            printf("Please Enter Valid Email Id : ");
            getchar();
            scanf("%[^\n]",ptr3->contacts[ptr3->contactCount].email);
            //printf("----------------------------------------------------------------\n");
            checkemailcorrect(ptr3);
        }
}
void mysearch(AddressBook *ptr4,char search[]){ //to search contact present or not
    int f=0,h=1;
    for(int i=0;i<=ptr4->contactCount;i++){
        if(strcmp(ptr4->contacts[i].name,search)==0){//to search contact present or not by using name
            f++;
            if(h){
                printf("--------------------------------------------------------------------------\n");
                printf("   sl.no        name                 mobile number               email \n");
                printf("-------------------------------------------------------------------------\n");
                h--;
            }
            printf("    %-10d%-25s%-30s%-20s \n\n",f,ptr4->contacts[i].name,ptr4->contacts[i].phone,ptr4->contacts[i].email); 
    
        }
        else if(strcmp(ptr4->contacts[i].phone,search)==0){//to search contact present or not by using phone number
            f++;
            if(h){
                printf("--------------------------------------------------------------------------\n");
                printf("   sl.no        name                   mobile number              email \n");
                printf("-------------------------------------------------------------------------\n");
                h--;
            }
            printf("   %-10d%-25s%-30s%-35s \n\n",f,ptr4->contacts[i].name,ptr4->contacts[i].phone,ptr4->contacts[i].email);    
        }
        else if(strcmp(ptr4->contacts[i].email,search)==0){//to search contact present or not by using email 
            f++;
            if(h){
                printf("--------------------------------------------------------------------------\n");
                printf("   sl.no        name                   mobile number                email \n");
                printf("-------------------------------------------------------------------------\n");
                h--;
            }
            printf("   %-10d%-25s%-30s%-35s \n\n",f,ptr4->contacts[i].name,ptr4->contacts[i].phone,ptr4->contacts[i].email);
        } 
    }
    if(!f){
        printf("------------------------------------------------\n"); //if is not found print not found
        printf("            the contact not found.\n");
        printf("------------------------------------------------\n");
    }
}
int myedit(AddressBook *ptr5,char *search){// to search contact and return position for editing
    int f=0,f2=0,arr[10],position;
    for(int i=0;i<=ptr5->contactCount;i++){
        if(strcmp(ptr5->contacts[i].name,search)==0){//to search contact present or not by using name
            f=1;
            arr[f2]=i;
            f2++;
            position=i;
            if(f2==1){
                printf("--------------------------------------------------------------------------\n");
                printf("   Sl.no        Name                   Mobile number                Email \n");
                printf("-------------------------------------------------------------------------\n");
            }
            printf("   %-10d%-25s%-30s%-35s \n",f2,ptr5->contacts[i].name,ptr5->contacts[i].phone,ptr5->contacts[i].email);
        }
        else if(strcmp(ptr5->contacts[i].phone,search)==0){//to search contact present or not by using number
            f=1;
            f2++;
            position=i;
            if(f2==1){
                printf("--------------------------------------------------------------------------\n");
                printf("   Sl.no        Name                   Mobile number                Email \n");
                printf("-------------------------------------------------------------------------\n");
            }
            printf("   %-10d%-25s%-30s%-35s \n",f2,ptr5->contacts[i].name,ptr5->contacts[i].phone,ptr5->contacts[i].email);
            
        }
        else if(strcmp(ptr5->contacts[i].email,search)==0){//to search contact present or not by using email
            f=1;
            f2++;
            position=i;
            if(f2==1){
                printf("--------------------------------------------------------------------------\n");
                printf("   Sl.no        Name                   Mobile number                Email \n");
                printf("-------------------------------------------------------------------------\n");
            }
            printf("  %-10d%-25s%-30s%-35s \n",f2,ptr5->contacts[i].name,ptr5->contacts[i].phone,ptr5->contacts[i].email);
        } 
    }
    if(!f){ // if it is not found
        printf("------------------------------------------------\n");
        printf("            the contact not found.\n");
        printf("------------------------------------------------\n");
        return -1;
    }
    else{ // more than one contact found in name
        if(f2>1){
            printf("------------------------------------------------\n");
            printf(" Please Select Contact  : ");
            int select;
            scanf("%d",&select);
            return arr[select-1];
        }     
        else{  
            return position; // return position
        }
    }
}
    
void nameedit(AddressBook *ptr,int result){ // this for name editing
    getchar();
    scanf("%[^\n]",ptr->contacts[result].name);
    char ch;
    for(int i=0;ptr->contacts[result].name[i]!='\0';i++){ //check only alphabets present or not
        ch=ptr->contacts[result].name[i];
        if(isalpha(ch)==0 && ch!=' '){
          printf("----------------------------------------------\n");
          printf("Please Enter Valid Name : ");
          getchar();
          scanf("%[^\n]",ptr->contacts[result].name);
          nameedit(ptr,result);     
        }   
    } 

}
void phoneedit(AddressBook *ptr,int result){ //this is for phone editing
    getchar();
    scanf("%[^\n]",ptr->contacts[result].phone);
    char ch;
    for(int i=0;ptr->contacts[result].phone[i]!='\0';i++){ // check for only digit or not
        ch=ptr->contacts[result].phone[i];
        if(!isdigit(ch)){
           printf("------------------------------------------------\n");
           printf("please enter only digits mobile number: ");
           getchar();
           scanf("%[^\n]",ptr->contacts[result].phone);
           phoneedit(ptr,result);
        }
    }
    if(strlen(ptr->contacts[result].phone)!=10){ //check contain only 10 digit or not
        printf("------------------------------------------------\n");
        printf("please enter 10 digits mobile number: ");
        getchar();
        scanf("%[^\n]",ptr->contacts[result].phone);
        phoneedit(ptr,result);
    }
    for(int i=0;i<=(ptr->contactCount);i++){ ////check already number exit or not
        if(strcmp(ptr->contacts[i].phone,ptr->contacts[result].phone)==0){
            printf("------------------------------------------------\n");
            printf("your adding aleardy exits phone number please enter new mobile number: ");
            getchar();
            scanf("%[^\n]",ptr->contacts[result].phone);
            phoneedit(ptr,result);
        }
    }
}
void emailedit(AddressBook *ptr,int result){
        getchar();
        scanf("%[^\n]",ptr->contacts[result].email);//this check @  character present or not
        if(strchr(ptr->contacts[result].email,'@')==NULL){
            printf("------------------------------------------------\n");
            printf("please enter valid email id: ");
            getchar();
            scanf("%[^\n]",ptr->contacts[result].email);
            emailedit(ptr,result);
        }
        else if(strstr(ptr->contacts[result].email,".com")==NULL){//this check .com  present or not
            printf("------------------------------------------------\n");
            printf("please enter valid email id: ");
            getchar();
            scanf("%[^\n]",ptr->contacts[result].email);
            emailedit(ptr,result);
        }
        char* p=strstr(ptr->contacts[result].email,"@");
        char* q=strstr(ptr->contacts[result].email,".com");
        char* x=p-1;
        char* y=q-1;
        if(  !isalnum(*x) ||  !isalnum(*y) ){//this check @ and .com has previous character present or not
            printf("------------------------------------------------\n");
            printf("please enter valid email id: ");
            getchar();
            scanf("%[^\n]",ptr->contacts[result].email);
            emailedit(ptr,result);
        }
}

void listContacts(AddressBook *addressBook) // to list all contacts using for loop
{
    // Sort contacts based on the chosen criteria
    int j=1;
    for(int i=0;i<(addressBook->contactCount);i++){
        if(j==1){
            printf("=======================                DETAILS                  =======================\n");
            printf("---------------------------------------------------------------------------------------\n");
            printf("   sl.no        name                mobile number                     email \n");
            printf("---------------------------------------------------------------------------------------\n");
            j=0;
        }
        printf("   %-10d%-25s%-30s%-30s \n",i+1,addressBook->contacts[i].name,addressBook->contacts[i].phone,addressBook->contacts[i].email);
        printf("---------------------------------------------------------------------------------------\n");
    }  
}
void initialize(AddressBook *addressBook) {
    addressBook->contactCount = 0;
    // populateAddressBook(addressBook);
    
    // Load contacts from file during initialization (After files)
    loadContactsFromFile(addressBook);
}
void createContact(AddressBook *addressBook)
{
    /*Define the logic to create a Contacts */
    printf("----------------------------------------------\n");
    printf("Please Enter Name : "); 
    getchar();
    scanf("%[^\n]",addressBook->contacts[addressBook->contactCount].name); // read name
    checknamecorrect(addressBook);
    printf("----------------------------------------------\n");
    printf("Please Enter Phone Number : ");
    getchar();
    scanf("%[^\n]",addressBook->contacts[addressBook->contactCount].phone); //read number
    checkmobilecorrect(addressBook);
    printf("----------------------------------------------\n");
    printf("Please Enter Gmail : ");
    getchar();
    scanf("%[^\n]",addressBook->contacts[addressBook->contactCount].email); //read email
    checkemailcorrect(addressBook);
    addressBook->contactCount++;
    printf("----------------------------------------------\n");
    
}

void searchContact(AddressBook *addressBook) 
{
    /* Define the logic for search */
    int choose;
    char  search[20];
    do{
        printf("---------------------------------------------------\n");
        printf("   <<<  The Option Which Would You Go For Search.  >>>\n");
        printf("---------------------------------------------------\n");
        printf(" 1. Search By Name\n");
        printf(" 2. Search By Phone Number\n");
        printf(" 3. Search By Email\n");
        printf("---------------------------------------------------\n");
        printf("Select Option: ");
        scanf("%d",&choose);  // read the option
        switch(choose){ // based on option jump to option
            case 1:
                printf("Please Enter Name Which You Have To Search : ");
                getchar();
                scanf("%[^\n]",search); //read name
                mysearch(addressBook,search);
                choose=4;
                break;
            case 2:
                printf("\nPlease Enter Phone Number Which You Have To Search : ");
                getchar();
                scanf("%[^\n]",search);//read number
                mysearch(addressBook,search);
                choose=4;
                break;
            case 3:
                printf("\nPlease Enter Email What You Have To Search : ");
                getchar();
                scanf("%[^\n]",search);//read gmail
                mysearch(addressBook,search);
                choose=4;
                break;
            default:
                printf("    Invalid choice. \n");
                choose=4;   
                break;
        }
    
    }while(choose!=4);

}

void editContact(AddressBook *addressBook)
{
	/* Define the logic for Editcontact */
    char  search2[20],new[20],f=1;
    int temp;
    printf("-------------------------------------------------------------\n");
    printf("choose the option which will you go for search to make edit.\n");
    printf("-------------------------------------------------------------\n");
    printf("1. Search By Name\n");
    printf("2. Search By Phone Number\n");
    printf("3. Search By Email\n");
    printf("------------------------------------------------------------\n");
    printf("Select Option: ");
    scanf("%d",&temp); //read name
    if(temp==1){
       printf("Please Enter Name: ");
       scanf(" %[^\n]",search2);
    }
    else if(temp==2){
        printf("Please Enter Phone Number: ");
        scanf(" %[^\n]",search2);
    }
    else if(temp==3){
        printf("Please Enter Gmail: ");
        scanf(" %[^\n]",search2);
    }
    else {
        f=0;
        printf("Invalid choice. \n");
        getchar();
        editContact(addressBook);
        
    }
    if(f){
    
     int result=myedit(addressBook,search2);
     if(result){ // if we found contact
     printf("------------------------------------------------------------\n");
     printf("              The Editing  Fieldes Are\n");
     printf("------------------------------------------------------------\n");
     int choose; 
     do{
        printf(" 1. Name\n");
        printf(" 2. Phone Number\n");
        printf(" 3. Email\n");
        printf("------------------------------------------------------------\n");
        printf("Please Select Option: ");
        scanf(" %d",&choose); // options for which field editing 
        switch(choose){
            case 1:
                printf("\nPlease Enter New Name: ");
                nameedit(addressBook,result); //call for name editing
                choose=4;
                break;
            case 2:
                printf("\nPlease Enter New Phone Number: ");
                phoneedit(addressBook,result); // call for number editing
                choose=4;
                break;
            case 3:
                printf("\nPlease Enter New Email: ");
                emailedit(addressBook,result); //call for email editing
                choose=4;
                break; 
            default:  
                printf("Invalid choice. \n");
                choose=4;
        }
     }while(choose!=4);
     }
    }
}

void deleteContact(AddressBook *addressBook)
{
	/* Define the logic for deletecontact */
    char  search[20];
    int temp;
    printf("------------------------------------------------------------\n");
    printf("      Which Would You Go For Search To Deleting \n");
    printf("------------------------------------------------------------\n");
    printf("1. Search By Name\n");
    printf("2. Search By Phone Number\n");
    printf("3. Search By Email\n");
    printf("------------------------------------------------------------\n");
    printf("Please Select Option: ");
    scanf("%d",&temp); //read the option
    if(temp==1){
       printf("\nPlease Enter Name: ");
       scanf(" %[^\n]",search);
    }
    //getchar();
    else if(temp==2){
        printf("\nPlease Enter Phone Number: ");
        scanf(" %[^\n]",search);
    }
    else if(temp==3){
        printf("\nPlease Enter Gmail: ");
        scanf(" %[^\n]",search);
    }
    else  {
        printf("Invalid choice. Please try again.\n");
        getchar();
        deleteContact(addressBook); // if is not present again call function
    }
    int result=myedit(addressBook,search); //return position to deleteng
    if(result!=-1){
      for(int i=result;i<(addressBook->contactCount);i++){
        strcpy(addressBook->contacts[i].name,addressBook->contacts[i+1].name);//swift name
        strcpy(addressBook->contacts[i].phone,addressBook->contacts[i+1].phone);//swift number
        strcpy(addressBook->contacts[i].email,addressBook->contacts[i+1].email);//swift gmail
      }
      addressBook->contactCount--;//decrease the size
    }

}
