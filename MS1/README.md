# Milestone 1 Specifications
###### Assembly Line - Inventory Items and Project Utilities

## Modules

- project (supplied)
- AssemblyLine (supplied)
- Utilities
<p>The Utilities module is a support module that contains the functionality that is common across the system. All objects in the system parse string data in the same way, use the same delimiter and report data fields in tabular format.</p>

The Utilities class for extracting tokens from a string, which consists of a set of fields separated by a specified delimiter and determining a field width that is sufficiently large to accommodate the tokens for a specified field. The field width is to be used to construct the output tables for the project. Tokens in a string are separated by one delimiter character

- ItemSet

ItemSet module is designed for managing the stock inventory of a particular item.

## Output

The output from the executable running Visual Studio with the following command line argument should look like:

```
Command Line : C:\Users\...\Debug\MS1.exe Inventory.txt

Inventory Assembly
==================

Items in Stock
--------------
CPU          [123456] Quantity 5   Description: Central Processing Unit
Memory       [654321] Quantity 10  Description: Basic Flash Memory
GPU          [456789] Quantity 2   Description: General Processing Unit
SSD          [987654] Quantity 5   Description: Solid State Drive
Power Supply [147852] Quantity 20  Description: Basic AC Power Supply

For Manual Validation
 getName(): CPU
 getSerialNumber(): 123456
 getQuantity(): 5
 getSerialNumber(): 123457
 getQuantity(): 4

Inventory Assembly Complete
```
