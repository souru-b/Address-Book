#include <stdio.h>
#include "file.h"
#include "contact.h"

void saveContactsToFile(AddressBook *addressBook) {
  FILE* fptr = fopen("populate.csv","w");
  if(fptr == NULL)
  {
    printf("File doesn't exit\n");
    return;
  }
  fprintf(fptr,"#%d\n",addressBook->contactCount);
  for(int i=0; i < addressBook->contactCount; i++)
  {
    fprintf(fptr,"%s,%s,%s\n",addressBook->contacts[i].name,addressBook->contacts[i].phone,addressBook->contacts[i].email);    
  }
  fclose(fptr); 
}

void loadContactsFromFile(AddressBook *addressBook) {
  // saveContactsToFile(addressBook); // Save contacts to file
  FILE* fptr = fopen("populate.csv","r");
  if(fptr == NULL)
  {
    printf("File doesn't exit\n");
    return;
  }
  fscanf(fptr,"#%d\n",&addressBook->contactCount);
  for(int i=0; i < addressBook->contactCount; i++)
  {
    fscanf(fptr,"%[^,],%[^,],%[^\n]\n",addressBook->contacts[i].name,addressBook->contacts[i].phone,addressBook->contacts[i].email);    
  }
  fclose(fptr); 
 
}
