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


