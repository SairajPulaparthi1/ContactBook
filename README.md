# ContactBook


The primary goal was to create a centralized database for contacts, optimizing memory usage by storing pointers to contact objects instead of duplicating their data across multiple devices. This approach ensures that each device only retains a reference to a single instance of each contact, significantly reducing memory consumption.

To accomplish this task, I implemented two classes: Contact and ContactBook. The Contact class encapsulates the attributes of a contact, including name and phone number, while the ContactBook class manages an array of pointers to Contact objects. This design enables efficient memory utilization and allows for the easy addition and removal of contacts. I ensured that the ContactBook class could handle operations such as adding new contacts, removing existing ones, and displaying the current contacts in a user-friendly format. Notably, I employed operator overloading to facilitate intuitive interactions with ContactBook instances, enabling seamless integration of contacts from different instances and maintaining the order of contacts during operations.

Throughout the project, I leveraged my understanding of C++ pointers and references to ensure the correct memory management of the Contact objects. By utilizing pointers, I reduced the overall memory footprint of the application, allowing for the efficient storage of potentially large datasets. The implementation included additional functionalities, such as sorting contacts alphabetically and ensuring the integrity of the contact data through proper methods for adding and removing contacts while maintaining the order of the array.

Overall, this project enhanced my proficiency in C++ programming, particularly in the areas of pointers, operator overloading, and memory management, while providing practical experience in developing a functional database system.
