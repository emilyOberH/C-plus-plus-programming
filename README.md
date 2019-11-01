# C-plus-plus-programming
Srt of exercised solved in C++.

    Lab 1:
  1) Program that asks the user to input 3 sides of a triangle, a, b and c. Program then informs user whether or not a triangle can be constructed with the given sides. If it is possible to form a triangle with the entered sides, the program outputs the perimeter and area of the triangle.
  
  2) Program asks user for the length of a dynamic array. After creating the array it fills it with values given by the user, displays the whole array, displays smallest and biggest value, displays the arithmetic average and displays the array in reversed order.
    
  3) Program asks user for the length of two dynamic square matrices, A and B. After creating the matrices it fills them with values given by the user, displays A and B, displays A+B and displays A*B.
  
    Lab 2:
  1) Define the class ShoppingCart supporting multi-item shoppings. The class should contain the following fields: a customer name and two arrays/lists of the same size (empty by default) – the first for product names (being strings) and the second one for costs (being real numbers) of the subsequent products. Implement the following public methods of the class :
  
        • the constructor with a string as a parameter being a customer name,
        
        • the copy-constructor and the assignment operator,
        
        • the destructor,
        
        • setCustomer and getCustomer methods,
        
        • addItem – with a product name as the first parameter (being string) and its cost as the second parameter (being a real value),
        
        • removeItem – with a product name as a parameter, removing the item from the the cart together with its cost (or throwing an error if the product is not in the cart),
        
        • size – returning the number of items in the shopping cart,
        
        • totalCost – returning the total cost of all the items in the cart,
        
        • getItemCount – returning the summary count of all the items in all the shopping carts currently available,
        
        • the indexing operator ([]) – with a product name as a parameter, returning the cost of the product placed within the cart (an error should be thrown for the product name not existing in the cart),
        
        • the shift operator (<<) – printing t
        
  2)  Define a class of travel Itinerary supporting multi-point routes. The class should contain the following fields: a description of the travel, two city names denoting the starting point and the ending point of the travel (being strings), a travel distance being a real number, and an array/list of city names (being strings) for additional via points (empty by default). Implement the following public methods of the class:
  
        • the constructor with three strings as parameters, denoting respectively: a description of the travel, and city names being the starting point and the ending point,
    
        • the copy-constructor and the assignment operator,
    
        • the destructor,
    
        • setDescription, getDescription, setDistance, getDistance methods (distances are in km),
    
        • addViaPoint – with a city name as a parameter, adding a new via point to the itinerary as the last via point,
    
        • removeViaPoint – with a city name as a parameter, removing the city from the via points of the itinerary (or throwing an error if the city is not in the itinerary),
    
        • size – returning the number of cities in the itinerary,
    
        • getSummaryDistance – returning the summary distance of all the itineraries currently available,
    
        • the indexing operator ([]) – returning the city name placed within the itinerary on the position given as a parameter (1 means the starting point, 2 means the first via point or the ending point for the shortest route, etc., an error should be thrown for the position exceeding the size of the itinerary),
    
        • the shift operator (<<) – printing the description, the distance and the list of all the successive cities in the itinerary
