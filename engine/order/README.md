# Order Design choice clarification

1. Since the biggest memeber in the Order Struct is uint64_t so 

our struct will head into the smallest size that is divisiable by 8 bytes

biggest member alignment

2. Order does not care about how much it was matched, it just cares about how much it has left

whoever cares about how much was matched will have to watch them

3. New demand for one stock at one price with an existing order in the market will arrive in another order to ensure equality

ie
Gray wants to buy 10 stock of ETH at price 20
Charlie wants to buy 10 stock of ETH at price 20

then now either of them wants to buy at price 20 will come later after the order or Charlie

4. The above only applies to inreases in ammount not decrease in ammount 

