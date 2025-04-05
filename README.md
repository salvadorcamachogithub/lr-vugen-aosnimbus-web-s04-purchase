Updated: 02.2025  
Script created by Salvador Camacho

This script was created with best practices, so it is more resilient, such as:
* Transaction naming
* No add cookies
* No third party
* One validation per transaction
* Think times at the end of each transaction to better simulate user behavior
* Main URL parametrized, Nimbus AOS by default: (http://nimbusserver.aos.com:8000)

This script sign ins, then randomly selects a product from the category and purchases it

Runtime Settings were set to log only on errors and generate snapshot on errors, think times 75% to 150%

This script has 8 transactions:  
AOS-Web-S04-01 Access AOS URL  
AOS-Web-S04-02 Sign In  
AOS-Web-S04-03 Speakers  
AOS-Web-S04-04 Random Product  
AOS-Web-S04-05 Add To Cart  
AOS-Web-S04-06 Checkout  
AOS-Web-S04-07 Order Payment Next and Pay Now  
AOS-Web-S04-08 Sign Out