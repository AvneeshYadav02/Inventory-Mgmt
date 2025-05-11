#include<stdio.h>
#include<stdlib.h>

// Declaration of functions
void save_inventory_list();//line79
void add_item();//line94
void show_items();//line104
void find_item();//line111
void update_item();//line127
void delete_item();//line149
void total_price();//line214

// struct for inventory items
struct Inventory{
    int id;
    char name[50];
    float price;
    int quantity;
}inventory[100];
int count=0;

// Main code for the program
int main(){
    //Opening the database file and storing everything in a struct array for easy access 
    FILE *fp;
    fp = fopen("Base.csv","r");
    if (fp==NULL){
        printf("Error Opening the file!");
        return 1;
    }
    char line[100];

    fgets(line, sizeof(line), fp);

    int i=0;
    while(fgets(line, sizeof(line), fp)){
        int id, amt;
        float price;
        char name[50];
        sscanf(line,"%d,%[^,],%f,%d", &inventory[i].id, inventory[i].name, &inventory[i].price, &inventory[i].quantity);         
        count = i;
        i++;       
    }

    printf("%d", count);
    // Loop to display menu and give exit controls
    int running = 0;
    while (running==0){
        int option=0;

        printf("\nMENU\n1. Add an item\n2. Show all items\n3. Find an item\n4. Update an item\n5. Delete an item\n6. Total worth\n0. Exit\n");
        option = getchar();

        while(getchar()!='\n');

        switch (option){
            case '1':
                add_item();
                break;
            case '2':
                show_items();
                break;
            case '3':
                find_item();
                break;
            case '4':
                update_item();
                break;
            case '5':
                delete_item();
                break;
            case '6':
                total_price();
                break;
            case '0':
                running++;
                break;
        }
        save_inventory_list();
    }

    return 0;
}


// Functions definition


// Function to save inventory list to the csv file
void save_inventory_list(){
    FILE *fp;
    fp = fopen("Base.csv","w");

    if (fp==NULL){
        printf("Could not open file.");
        exit(1);
    }

    fprintf(fp, "Product ID,Item Name,Price,Quantity\n");
    for(int i=0;i<=count;i++){
        if(i == count){
            fprintf(fp,"%d,%s,%.2f,%d",inventory[i].id,inventory[i].name,inventory[i].price,inventory[i].quantity);
        }
        else{
            fprintf(fp,"%d,%s,%.2f,%d\n",inventory[i].id,inventory[i].name,inventory[i].price,inventory[i].quantity);
        }
    }
    
    fclose(fp);
}

// Function to add items
void add_item(){
    char user_input[100];
    count++;

    printf("Enter the product details (ID,Name,Price,Quantity): ");
    fgets(user_input, sizeof(user_input), stdin);
    sscanf(user_input, "%d,%[^,],%f,%d", &inventory[count].id, inventory[count].name, &inventory[count].price, &inventory[count].quantity);
}

// Function to show items:
void show_items(){
    for(int i=0; i<=count; i++){
        printf("\n%d--> | ID: %d | Name: %s | Price: %.2f | Quantity: %d |\n",(i+1),inventory[i].id,inventory[i].name,inventory[i].price,inventory[i].quantity);
    }
}

// Function to find item
void find_item(){
    int product_id=0;

    printf("\nEnter the Product ID: ");
    scanf("%d", &product_id);

    int i=0;
    int found = 0;

    for(i=0; i<=count; i++){
        if (product_id == inventory[i].id){
            printf("|ID: %d|Name: %s|Price: %.2f|Quantity: %d|",inventory[i].id,inventory[i].name,inventory[i].price,inventory[i].quantity);
            found++;
            break;
        }
    }

    if (found==0){
        printf("\nItem not found.\n");
    }
}

// Function to update item
void update_item(){
    int product_id=0;
    char new_dat[100];

    printf("\nEnter the Product ID: ");
    scanf("%d", &product_id);

    while(getchar()!='\n');

    int i=0;
    int found = 0;

    for(i=0; i<=count; i++){
        if (product_id == inventory[i].id){
            found++;
            break;
        }
    }

    if (found==0){
        printf("\nItem not found.\n");
    }
    else{
        printf("Enter the new product details (ID,Name,Price,Quantity): ");
        fgets(new_dat, sizeof(new_dat), stdin);
        sscanf(new_dat, "%d,%[^,],%f,%d",&inventory[i].id, inventory[i].name,&inventory[i].price,&inventory[i].quantity);
        printf("\nUpdated Item stat:\n|ID: %d|Name: %s|Price: %.2f|Quantity: %d|",inventory[i].id,inventory[i].name,inventory[i].price,inventory[i].quantity);
    }
}

// Function to delete item
void delete_item(){
    int delete_id = 0;

    printf("Enter the Product ID of the item you wish to delete: ");
    scanf("%d", &delete_id);

    while(getchar() != '\n');
    
    int i=0;
    int found = 0;
    
    for(i=0; i<=count; i++){
        if (delete_id == inventory[i].id){
            found++;
            break;
        }
    }
    
    if (found==0){
        printf("\nItem not found.\n");
    }
    else{
        for(int j = i; j<count; j++){
            inventory[j]=inventory[j+1];
        }
        count--;
        printf("\nItem Deleted.\n");
    }
    
}

// Function to calculate the total value of all items
void total_price(){
    float *total;
    total = malloc(sizeof(float));

    *total = 0.0;

    if (total==NULL){
        printf("Memory allocation failed!");
        exit(1);
    }
    
    for(int i=0; i<=count; i++){
        *total += (inventory[i].price*inventory[i].quantity);
    }

    printf("Your total inventory is worth ₹%.2f", *total);
    free(total);
    total = NULL;
}