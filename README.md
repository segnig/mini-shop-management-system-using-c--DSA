## Inventory Management System v1.0

**Introduction**

This document outlines the functionalities and usage of the provided C++ code, which implements a core inventory management system with a user interface for shop management and customer interaction.

**Features**

* **Shop Management:**
    * **Inventory Management:**
        * Add new items to the inventory (option to specify placement).
        * Delete existing items from the inventory.
        * View a comprehensive list of all available items.
        * Search for specific items based on their name.
    * **Order Processing:**
        * View a history of customer actions and orders.
        * Process successful order completion, updating both inventory quantity and shop's balance.
* **Customer Interface:**
    * Browse the available inventory list.
    * Search for specific items by name.
    * Place orders for desired items.
    * Check their current account balance.

**Data Structures**

* **Node:** Encapsulates information about a single item in the inventory (name, manufacturing date, expiry date, quantity, cost).
* **history:** Tracks a chronological record of actions performed within the system (adding, deleting, searching items).
* **order:** Stores details pertaining to customer orders (customer name, address, ordered item, quantity).

**Running the System**

1. Compile the provided C++ code using a compatible C++ compiler.
2. Execute the compiled program.

**Important Considerations**

* **Current limitations:**
    * Data Persistence: The system lacks a mechanism to permanently save or load data.
    * Error Handling:  Limited checks exist for invalid user input or unexpected scenarios.
    * Memory Management: The code utilizes raw pointers, potentially leading to memory leaks if not addressed.
* **Recommended improvements:**
    * Implement data persistence mechanisms (e.g., files, databases).
    * Enhance error handling for a more robust user experience.
    * Integrate proper memory management practices (e.g., smart pointers).
    * Consider incorporating additional functionalities like user authentication, advanced search options, etc.

**Disclaimer**

This code serves as a foundational framework for a shop inventory system. Real-world applications would necessitate a more comprehensive design, incorporating robust security measures and additional features tailored to specific business requirements.
