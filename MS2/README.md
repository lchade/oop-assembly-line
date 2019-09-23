# Milestone 2 Specifications
###### Assembly Line - Customer Orders

## Modules

- project (supplied)
- AssemblyLine (supplied)
- CustomerOrder

The CustomerOrder module contains all the functionality for handling customer orders as they move along the assembly line. As the line manager moves an order along the assembly line, the station where that order currently rests fills a request for an item of that station, if there is any such request. Once the order has reached the end of the line, the order is either completed or incomplete. One cause of incompleteness is the lack of sufficient items in stock at a station.

CustomerOrder module is designed for managing and processing customer orders. Customer order objects are unique and hence neither copyable nor copy-assignable. However, they are both movable and move-assignable. 
 
- Utilities (from Milestone 1)
- ItemSet (from Milestone 1)


## Output

The output from the executable running Visual Studio with the following command line argument should look like:

```
Command Line : C:\Users\...\Debug\MS2.exe Inventory.txt CustomerOrders.txt

Customer Order Assembly
=======================

Items in Stock
--------------
CPU          [123456] Quantity 5   Description: Central Processing Unit
Memory       [654321] Quantity 10  Description: Basic Flash Memory
GPU          [456789] Quantity 2   Description: General Processing Unit
SSD          [987654] Quantity 5   Description: Solid State Drive
Power Supply [147852] Quantity 20  Description: Basic AC Power Supply

For Manual Validation: Item 1
 getName(): CPU
 getSerialNumber(): 123456
 getQuantity(): 5
 getSerialNumber(): 123457
 getQuantity(): 4

Customer Orders
---------------
Elliott C.   [Gaming PC]
             CPU
             Memory
             GPU
             GPU
             GPU
             SSD
             Power Supply
Chris S.     [Laptop]
             CPU
             Memory
             SSD
             Power Supply
Mary-Lynn M. [Desktop PC]
             CPU
             Memory
             Power Supply
Chris T.     [Micro Controller]
             GPU
             GPU
             Power Supply
             SSD

For Manual Validation
Chris T.     [Micro Controller]
             GPU
             GPU
             Power Supply
             SSD
Chris T.     [Micro Controller]
             GPU
             GPU
             Power Supply
             SSD

Chloe        [Flight PC]
             CPU
             GPU
             Power Supply
Mary-Lynn M. [Desktop PC]
             CPU
             Memory
             Power Supply

For Manual Validation Filling
Mary-Lynn M. [Desktop PC]
             CPU
             Memory
             Power Supply
 isFilled(): false
 Filled Mary-Lynn M. [Desktop PC][CPU][123457]
 isFilled(): false
 Unable to fill Mary-Lynn M. [Desktop PC][CPU][123457] already filled
 Filled Mary-Lynn M. [Desktop PC][Memory][654321]
 Filled Mary-Lynn M. [Desktop PC][Power Supply][147852]
 isFilled(): true

Customer Order Assembly Complete 
```
