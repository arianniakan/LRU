# LRU
A “Least Recently Used Updater” circuit (LRU), which is used in page replacement of memory management. Done in SystemC


Page replacement is a widely used
approach in memory management. The idea is simple: the main memory cannot hold all the
referred pages in memory. So whenever a new page is referenced, an existing page is replaced by
the page that was newly called. The goal of any page replacement mechanism is to minimize the
number of page faults.

![image](https://user-images.githubusercontent.com/65303603/171609080-b9de429c-9a4a-41b6-a762-e66796ebc602.png)

We have sixteen pages with tags from 0 to 15 (0 is the most recently used and 15 is
the least recently used). The tag of each page is defined using a 4-bit binary number that are kept
in a Memory. As shown in figure 1, the Memory needs a 4-bit address bus and two 4-bit data buses.
NewPageBus input provides the ID of the current page that has just been accessed. A pulse on the
completed input shows that the page access has been completed and the LRU memory needs to be
updated. All pages with lower tag than the tag of the recently accessed page must increment theirtag by one.

To do this, this module examines all entries of the memory one by one and increments tags
that are lower than that of the current page. The entry that corresponds to the current page will
be set to zero indicating this page is the most recently used. Other entries that have higher tag
values will be kept intact. After updating the Memory, the output free signal becomes one. (as
an example see figure 2)
![image](https://user-images.githubusercontent.com/65303603/171609347-04bef0d0-0665-42e3-ae48-b6414b3e4ef9.png)


The DataPath and Controller of this circuit are as follows:
![photo1653568208](https://user-images.githubusercontent.com/65303603/171609683-a46d4d27-24e5-4bdf-ba06-a9f7b52d7e20.jpeg)
![image](https://user-images.githubusercontent.com/65303603/171609714-a1df9ae3-fcd3-40da-95e3-1bc46d8700a8.png)

They are Implimented and tested using SystemC, which can be seen in the main codes directory as LRU_DP ans LRU_CP
the modules used in them, like the incrementer and subtractor are also Implimented and have their own respective .h files in the main directory.

this circuit was tested in the main.cpp file using a SystemC test bench which is found in the main Directory as LRU_TB 
the VCD output waveform for 7 put on the NewPageBus is as follows:
![image](https://user-images.githubusercontent.com/65303603/171610510-1c2cf3b9-8a46-4551-a031-50eee0689f3a.png)

There's also a difrent design and Implimentation of this LRU in this projevt
