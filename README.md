# Inventory Management System (C)

A command-line inventory management system written in C. This system allows users to add, show, find, update, delete items, and calculate the total worth of the inventory. It stores inventory data in a CSV file for persistence and allows for easy management of products and their details.

## 🛠️ Features

- **Add an Item**: Add new products to the inventory with ID, name, price, and quantity.
- **Show All Items**: View all products currently stored in the inventory.
- **Find an Item**: Search for a product by its ID and view its details.
- **Update an Item**: Modify an existing product's details.
- **Delete an Item**: Remove an item from the inventory.
- **Total Worth**: Calculate the total value of all items in the inventory.

## 📁 Project Structure

```
inventory-management/
├── main.c            # Main program and menu loop
└── Base.csv          # CSV file storing the inventory data
```

## ⚙️ Functions

- `save_inventory_list()`: Saves the inventory data to a CSV file.
- `add_item()`: Adds a new product to the inventory.
- `show_items()`: Displays all products in the inventory.
- `find_item()`: Finds and displays details of a product by its ID.
- `update_item()`: Updates the details of an existing product.
- `delete_item()`: Deletes a product from the inventory.
- `total_price()`: Calculates the total value of the inventory.

## 🚀 Getting Started

1. Install a C compiler like GCC.
2. Clone the repository:

```bash
git clone https://github.com/your-username/inventory-management.git
cd inventory-management
```

3. Compile and run the program:

```bash
gcc main.c -o inventory-management
./inventory-management
```

Created to demonstrate inventory management system functionality in C, using file handling and basic data structures.
