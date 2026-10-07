# 1/10/26

Hi the world, this is day one 

I am just trying to understand what is actually happening on in this project

What should I do ? 

okay so so far I know that what I gonna do is like an eco system, containing both side 

Clients and server 

well because I dont know too much about trading, so this one is to teach me about trading system :D 

# 4/10/26

Okay so well when writing out the example, I stumbled on a bunch of stuff as writing the first ever order isnt that easy to me ish. A bunch of profounding question i suppose.

So the way I used to understand what is going on is as follow 

I am some dude at the market fair. At this stage right now, I am the CEO as well as the employee as well cleaner, board writer and everything

I will have one line of customers - which later on gonna be a bunch of booths, each taken care of by each one of my employees - for right now, it is me who gonna hear them, noting down what they want and then match their order and even notify them.

The way I am understanding this server is at this moment, I am building the exchange server first, or me being the HOSE (Hochiminh Stock Exchange). Later on when writing about the client, I gonna be Optiver, JS, IMC ish.

About the big discovery today, I found out that well, board management today is pretty much just sequential, it is still first come first serve, one big lock on the board. 

Multiple subboard lock is somewhate feasible but mostly just not worth it, because imagining in the case of employee A locking customer B wait on C to unlock , while employee Z locking customer C waiting on B - a deadlock. So normally still board per person, not subsection block 

Oh and i learnt about Optiver , JS, IMC,... they are "market maker". Today I learnt about what is a "market maker" lol. A client who has order both on sell and buy end , they are market maker. Well and the HFT secrets is they have their own algo to work out what is the "perfect" number of quantity x price to buy/sell for each of stock on both end + the ability to cancel/adjust their order in lighting speed. 

In term of multi-threaded or parallelism work , well the HOSE job related to the board is mainly related to sequential , benefits from CPU more than GPU - a nicely fact that clears me out of the confusion that it is not hardware limitation that makes we utilize the CPU more than GPU. It is the nature of the jobs. Of course there are aspects that can be solved paralelly - where multithreaded gonna be more relevant 

Well after finishing with the HOSE, i will move onto being optiver

Oh and yea, I need to get the order done working tomorrow

# 5/10/26

Only non-MARKET order will stay in the order book 

Every orders in the book are of type LIMIT

We will have one internal private look and then one for the client

For listing problems, we will choose a data structure that is always in order 
+( my guess right now is we will implement heap ) - but stay tuned as it is the next lessson
+
+Buyer comes and buy lowest firsts
+
+Id overflow , an unsigned int 64 has 2^64 - 1, we can even reset id daily
+- we may have day field along with timestamp
+
+In our project, anything unfilled gonna be cancel 
+
+
+In term of data flow, this is what we would do: 
+
+
+
+private board the source of truth of everything 
+ie any adjustment will be done on the "private" board 
+
+and then for the public board - or the board that is being seen by other people
+
+it will only act as a read only monitor and the mech is 
+
+whenever there is any change from the private book , it will "announce" the public book - via somekind of API or something else  - will be decided in later steps
+
+that is for data flow 
+
+
+ahh freak , today time is about to sum up , tomorrow, comeback and I want you to check on this : 
+
+0. dataflow: why it said that engine does not announce to the public board, it annoucnes events, publishers listens and maintains the public board - why it say this
+
+1. Reorder the read me 
+2. A livng question about the main.cpp - you need to figure out 
+- why the whole engine is just lib and no executation
+- where in the Catch 2 lib lay the main.cpp
+- why it said there is a lot of main.cpp here and there and our engine is just static code in 1 place
+- investigate the output and template it gives 
+- what do you mean by this is not the main program or what does it mean when it say there is no main program ? 
+
+ref: https://claude.ai/chat/326d31b2-b7af-4a5d-b023-12861984f37e
+

# 6/10/26

Order is struct because we have no invariant to protect

price: double or float 

fractional parts are built from negative power of 2 ! 

```
0.5   = 2⁻¹
0.25  = 2⁻²
0.125 = 2⁻³
0.75  = 0.5 + 0.25          ✓ exact
0.1   = 0.0625 + 0.03125 + ... never ends   ✗
```

```
int64_t  a = -1;
uint64_t b = 5;
a < b   // false! -1 became 18446744073709551615
```

When c++ combines unsigned with signed numbers it turns the signed into unsigned and it breaks stuff ! 

Tomorrow question:

Three decisions remain for order.hpp. Make them, then write the whole struct:

id: you did the overflow math earlier. Is it ever subtracted or mixed with prices? Does that change signed vs unsigned?
side and type: how do you represent BUY/SELL and LIMIT/MARKET? Look up enum class versus plain enum, and pick one with a reason.
quantity: one field or two? Think back to the exercise. After step 3, Carol's order showed 10. What did she originally send, and does anyone still need that number?

# 7/10/26

One of the compiler job is that it will round a struct size up to multiple of its largest member alignment

ie in a Struct that have an uint64_t then that struct will eventually have the size of 8(bytes) * something 


