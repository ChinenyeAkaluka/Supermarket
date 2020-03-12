# Supermarket
Using a discrete-event simulation to simulate customers getting through the checkout lanes in a supermarket. Implemented two different types of checkout systems: Normal lane, express lane
## c++ object orientation and polymorphism
## Example 
Simulation begins...
Time 1: Customer 1 arrives: BIG: 12 Service time: 24

Time 1: Customer 1 begins service in Express lane

Time 21: Customer 2 arrives: SMALL: 2 BIG: 3 COUPON: 1 Service time: 13

Time 25: Customer 1 completes service in Express lane. Arrival: 1 Complete: 25 Wait: 0

Time 25: Customer 2 begins service in Express lane

Time 36: Customer 3 arrives: BIG: 4 FORV: 2 Service time: 16

Time 38: Customer 2 completes service in Express lane. Arrival: 21 Complete: 38 Wait: 4

Time 38: Customer 3 begins service in Express lane

Time 38: Customer 4 arrives: SMALL: 14 BIG: 1 Service time: 16

Time 38: Customer 4 begins service in Regular lane

Time 53: Customer 5 arrives: SMALL: 33 BIG: 55 FORV: 11 COUPON: 3 Service time: 202

Time 54: Customer 3 completes service in Express lane. Arrival: 36 Complete: 54 Wait: 2

Time 54: Customer 4 completes service in Regular lane. Arrival: 38 Complete: 54 Wait: 0

Time 54: Customer 5 begins service in Regular lane

Time 75: Customer 6 arrives: SMALL: 4 BIG: 2 FORV: 5 COUPON: 2 Service time: 38

Time 75: Customer 6 begins service in Express lane

Time 113: Customer 6 completes service in Express lane. Arrival: 75 Complete: 113 Wait: 0

Time 124: Customer 7 arrives: SMALL: 7 BIG: 3 FORV: 2 COUPON: 10 Service time: 71

Time 124: Customer 7 begins service in Express lane

Time 195: Customer 7 completes service in Express lane. Arrival: 124 Complete: 195 Wait: 0

Time 256: Customer 5 completes service in Regular lane. Arrival: 53 Complete: 256 Wait: 1

... simulation ended.
###### Summary ######
- Total number of customers: 7
- Service time: total = 380, average = 54.2857
- Waiting time: total = 7, average = 1
