Action()
{
	
/*

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

This script has 8 transactions
AOS-Web-S04-01 Access AOS URL
AOS-Web-S04-02 Sign In
AOS-Web-S04-03 Speakers
AOS-Web-S04-04 Random Product
AOS-Web-S04-05 Add To Cart
AOS-Web-S04-06 Checkout
AOS-Web-S04-07 Order Payment Next and Pay Now
AOS-Web-S04-08 Sign Out

*/
	
	web_set_sockets_option("SSL_VERSION", "AUTO");
	
	web_reg_find("Text=Advantage Shopping", 
		LAST);

lr_start_transaction("AOS-Web-S04-01 Access AOS URL");

	web_url("Main AOS URL", 
		"URL={AOS_URL}/", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=", 
		"Snapshot=t31.inf", 
		"Mode=HTML", 
		EXTRARES, 
		"Url=/main.min.js", ENDITEM, 
		"Url=/css/fonts/roboto_regular_macroman/Roboto-Regular-webfont.woff", "Referer={AOS_URL}/css/main.min.css", ENDITEM, 
		"Url=/services.properties", ENDITEM, 
		"Url=/css/fonts/roboto_light_macroman/Roboto-Light-webfont.woff", "Referer={AOS_URL}/css/main.min.css", ENDITEM, 
		"Url=/css/fonts/roboto_medium_macroman/Roboto-Medium-webfont.woff", "Referer={AOS_URL}/css/main.min.css", ENDITEM, 
		"Url=/css/images/logo.png", ENDITEM, 
		"Url=/css/images/closeDark.png", ENDITEM, 
		"Url=/css/images/arrow_right.png", "Referer={AOS_URL}/css/main.min.css", ENDITEM, 
		"Url=/css/fonts/roboto_thin_macroman/Roboto-Thin-webfont.woff", "Referer={AOS_URL}/css/main.min.css", ENDITEM, 
		"Url=/css/fonts/roboto_bold_macroman/Roboto-Bold-webfont.woff", "Referer={AOS_URL}/css/main.min.css", ENDITEM, 
		"Url=/catalog/fetchImage?image_id=headphones", ENDITEM, 
		"Url=/catalog/fetchImage?image_id=mice", ENDITEM, 
		"Url=/catalog/fetchImage?image_id=laptops", ENDITEM, 
		"Url=/css/images/Banner1.jpg", ENDITEM, 
		"Url=/catalog/fetchImage?image_id=tablets", ENDITEM, 
		"Url=/catalog/fetchImage?image_id=speakers", ENDITEM, 
		"Url=/css/images/Special-offer.jpg", ENDITEM, 
		"Url=/css/images/GoUp.png", ENDITEM, 
		"Url=/css/images/facebook.png", ENDITEM, 
		"Url=/css/images/twitter.png", ENDITEM, 
		"Url=/css/images/linkedin.png", ENDITEM, 
		"Url=/css/images/Banner2.jpg", ENDITEM, 
		"Url=/css/images/Banner3.jpg", ENDITEM, 
		"Url=/css/images/Popular-item3.jpg", ENDITEM, 
		"Url=/css/images/Popular-item1.jpg", ENDITEM, 
		"Url=/css/images/Popular-item2.jpg", ENDITEM, 
		"Url=/css/images/FacebookLogo.png", "Referer={AOS_URL}/css/main.min.css", ENDITEM, 
		"Url=/css/images/Filter.png", ENDITEM, 
		"Url=/css/images/category_banner_4.png", ENDITEM, 
		"Url=/catalog/fetchImage?image_id=4200", ENDITEM, 
		"Url=/catalog/fetchImage?image_id=4600", ENDITEM, 
		"Url=/catalog/fetchImage?image_id=4700", ENDITEM, 
		"Url=/catalog/fetchImage?image_id=4300", ENDITEM, 
		"Url=/catalog/fetchImage?image_id=4500", ENDITEM, 
		"Url=/catalog/fetchImage?image_id=4100", ENDITEM, 
		"Url=/catalog/fetchImage?image_id=4400", ENDITEM, 
		"Url=/css/images/Bell.png", "Referer={AOS_URL}/css/main.min.css", ENDITEM, 
		"Url=/css/images/Check.png", "Referer={AOS_URL}/css/main.min.css", ENDITEM, 
		"Url=/css/images/User.jpg", ENDITEM, 
		"Url=/css/images/Shipex.png", ENDITEM, 
		"Url=/css/images/SafePay.png", ENDITEM, 
		"Url=/css/images/Master_credit.png", ENDITEM, 
		LAST);

	web_url("ALL", 
		"URL={AOS_URL}/catalog/api/v1/DemoAppConfig/parameters/by_tool/ALL", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer={AOS_URL}/", 
		"Snapshot=t32.inf", 
		"Mode=HTML", 
		LAST);

	web_custom_request("GetAccountConfigurationRequest", 
		"URL={AOS_URL}/accountservice/ws/GetAccountConfigurationRequest", 
		"Method=POST", 
		"Resource=0", 
		"RecContentType=text/xml", 
		"Referer={AOS_URL}/", 
		"Snapshot=t33.inf", 
		"Mode=HTML", 
		"EncType=text/xml; charset=UTF-8", 
		"Body=<?xml version=\"1.0\" encoding=\"UTF-8\"?><soap:Envelope xmlns:soap=\"http://schemas.xmlsoap.org/soap/envelope/\" xmlns:xsi=\"http://www.w3.org/2001/XMLSchema-instance\" xmlns:xsd=\"http://www.w3.org/2001/XMLSchema\"><soap:Body><GetAccountConfigurationRequest xmlns=\"com.advantage.online.store.accountservice\"></GetAccountConfigurationRequest></soap:Body></soap:Envelope>", 
		LAST);

	web_url("categories", 
		"URL={AOS_URL}/catalog/api/v1/categories", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer={AOS_URL}/", 
		"Snapshot=t34.inf", 
		"Mode=HTML", 
		LAST);

	web_url("search", 
		"URL={AOS_URL}/catalog/api/v1/deals/search?dealOfTheDay=true", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer={AOS_URL}/", 
		"Snapshot=t35.inf", 
		"Mode=HTML", 
		LAST);

	web_url("popularProducts.json", 
		"URL={AOS_URL}/app/tempFiles/popularProducts.json", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer={AOS_URL}/", 
		"Snapshot=t36.inf", 
		"Mode=HTML", 
		LAST);

	web_url("home-page.html", 
		"URL={AOS_URL}/app/views/home-page.html", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer={AOS_URL}/", 
		"Snapshot=t37.inf", 
		"Mode=HTML", 
		LAST);

lr_end_transaction("AOS-Web-S04-01 Access AOS URL",LR_AUTO);

	lr_think_time(10);
	
	// 101168423
	web_reg_save_param_xpath(
		"ParamName=userId",
		"QueryString=//ns2:userId/text()",
		SEARCH_FILTERS,
		"Scope=Body",
		LAST);
	
	// TWVyY3VyeTpNZXJjdXJ5	
	web_reg_save_param_xpath(
		"ParamName=t_authorization",
		"QueryString=//ns2:t_authorization/text()",
		SEARCH_FILTERS,
		"Scope=Body",
		LAST);

lr_start_transaction("AOS-Web-S04-02 Sign In");

	web_custom_request("AccountLoginRequest", 
		"URL={AOS_URL}/accountservice/ws/AccountLoginRequest", 
		"Method=POST", 
		"Resource=0", 
		"RecContentType=text/xml", 
		"Referer={AOS_URL}/", 
		"Snapshot=t38.inf", 
		"Mode=HTML", 
		"EncType=text/xml; charset=UTF-8", 
		"Body=<?xml version=\"1.0\" encoding=\"UTF-8\"?><soap:Envelope xmlns:soap=\"http://schemas.xmlsoap.org/soap/envelope/\" xmlns:xsi=\"http://www.w3.org/2001/XMLSchema-instance\" xmlns:xsd=\"http://www.w3.org/2001/XMLSchema\"><soap:Body><AccountLoginRequest xmlns=\"com.advantage.online.store.accountservice\"><email></email><loginPassword>{loginUser}</loginPassword><loginUser>{loginUser}</loginUser></AccountLoginRequest></soap:Body></soap:Envelope>", 
		LAST);
		
	web_add_header("Authorization",
		"Basic {t_authorization}");

/*Correlation comment - Do not change!  Original value='AF8A0F4202B5D9560631C5905460A848' Name ='sessionId' Type ='Manual'*/
	web_reg_save_param_regexp(
		"ParamName=sessionId",
		"RegExp=JSESSIONID=(.*?);",
		SEARCH_FILTERS,
		"Scope=Cookies",
		"IgnoreRedirections=No",
		LAST);

	web_url("userId", 
		"URL={AOS_URL}/order/api/v1/carts/{userId}", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer={AOS_URL}/", 
		"Snapshot=t39.inf", 
		"Mode=HTML", 
		LAST);

lr_end_transaction("AOS-Web-S04-02 Sign In",LR_AUTO);

	lr_think_time(10);
	
	
	web_reg_save_param_json(
		"ParamName=productId",
		"QueryString=$..products..productId",
		"SelectAll=Yes",
		LAST);

lr_start_transaction("AOS-Web-S04-03 Speakers");

	web_url("products", 
		"URL={AOS_URL}/catalog/api/v1/categories/4/products", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer={AOS_URL}/", 
		"Snapshot=t40.inf", 
		"Mode=HTML", 
		LAST);

	web_url("attributes", 
		"URL={AOS_URL}/catalog/api/v1/categories/attributes", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer={AOS_URL}/", 
		"Snapshot=t41.inf", 
		"Mode=HTML", 
		LAST);
		
	web_reg_find("Text=category-type-products", 
		LAST);

	web_url("category-page.html", 
		"URL={AOS_URL}/app/views/category-page.html", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer={AOS_URL}/", 
		"Snapshot=t42.inf", 
		"Mode=HTML", 
		LAST);

lr_end_transaction("AOS-Web-S04-03 Speakers",LR_AUTO);

	lr_think_time(10);
	
	
	// Random Value for productId
	lr_save_string(lr_paramarr_random("productId"),"randomProductId");
	
	web_reg_save_param_json(
		"ParamName=colors",
		"QueryString=$..colors[?(@.inStock)].code",
		"SelectAll=Yes",
		LAST);

lr_start_transaction("AOS-Web-S04-04 Random Product");

	web_url("randomProduct", 
		"URL={AOS_URL}/catalog/api/v1/products/{randomProductId}", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer={AOS_URL}/", 
		"Snapshot=t43.inf", 
		"Mode=HTML", 
		LAST);

	web_url("all_data", 
		"URL={AOS_URL}/catalog/api/v1/categories/all_data", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer={AOS_URL}/", 
		"Snapshot=t44.inf", 
		"Mode=HTML", 
		LAST);

	web_url("products_2", 
		"URL={AOS_URL}/catalog/api/v1/categories/4/products", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer={AOS_URL}/", 
		"Snapshot=t45.inf", 
		"Mode=HTML", 
		LAST);
		
	web_reg_find("Text=productProperties", 
		LAST);

	web_url("product-page.html", 
		"URL={AOS_URL}/app/views/product-page.html", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer={AOS_URL}/", 
		"Snapshot=t46.inf", 
		"Mode=HTML", 
		LAST);

lr_end_transaction("AOS-Web-S04-04 Random Product",LR_AUTO);

	lr_think_time(10);
	
	
	// Random Value for color
	lr_save_string(lr_paramarr_random("colors"),"color");
	
	web_add_header("Authorization",
		"Basic {t_authorization}");
	
	web_reg_find("Text=productsInCart", 
		LAST);

lr_start_transaction("AOS-Web-S04-05 Add To Cart");

	web_submit_data("AddToCart",
		"Action={AOS_URL}/order/api/v1/carts/{userId}/product/{randomProductId}/color/{color}?quantity=1",
		"Method=POST",
		"RecContentType=application/json",
		"Referer={AOS_URL}/",
		"Snapshot=t47.inf",
		"Mode=HTML",
		ITEMDATA,
		"Name=sessionId", "Value={sessionId}", ENDITEM,
		LAST);

lr_end_transaction("AOS-Web-S04-05 Add To Cart",LR_AUTO);

	lr_think_time(10);
	
	
/*Correlation comment: Automatic rules - Do not change!  
Original value='Jerusalem' 
Name ='cityName' 
Type ='Manual'*/
	web_reg_save_param_xpath(
		"ParamName=cityName",
		"QueryString=//ns2:cityName/text()",
		SEARCH_FILTERS,
		"Scope=Body",
		LAST);

/*Correlation comment: Automatic rules - Do not change!  
Original value='077-7654321' 
Name ='phoneNumber' 
Type ='Manual'*/
	web_reg_save_param_xpath(
		"ParamName=phoneNumber",
		"QueryString=//ns2:phoneNumber/text()",
		SEARCH_FILTERS,
		"Scope=Body",
		LAST);

/*Correlation comment - Do not change!  Original value='9876543' Name ='zipcode' Type ='Manual'*/
	web_reg_save_param_xpath(
		"ParamName=zipcode",
		"QueryString=//ns2:zipcode/text()",
		SEARCH_FILTERS,
		"Scope=Body",
		"IgnoreRedirections=No",
		LAST);

/*Correlation comment: Automatic rules - Do not change!  
Original value='Jerusalem1' 
Name ='stateProvince' 
Type ='Manual'*/
	web_reg_save_param_xpath(
		"ParamName=stateProvince",
		"QueryString=//ns2:stateProvince/text()",
		SEARCH_FILTERS,
		"Scope=Body",
		LAST);
		
lr_start_transaction("AOS-Web-S04-06 Checkout");

	web_custom_request("GetAccountByIdRequest", 
		"URL={AOS_URL}/accountservice/ws/GetAccountByIdRequest", 
		"Method=POST", 
		"Resource=0", 
		"RecContentType=text/xml", 
		"Referer={AOS_URL}/", 
		"Snapshot=t48.inf", 
		"Mode=HTML", 
		"EncType=text/xml; charset=UTF-8", 
		"Body=<?xml version=\"1.0\" encoding=\"UTF-8\"?><soap:Envelope xmlns:soap=\"http://schemas.xmlsoap.org/soap/envelope/\" xmlns:xsi=\"http://www.w3.org/2001/XMLSchema-instance\" xmlns:xsd=\"http://www.w3.org/2001/XMLSchema\"><soap:Body><GetAccountByIdRequest xmlns=\"com.advantage.online.store.accountservice\"><accountId>{userId}</accountId><base64Token>Basic {t_authorization}</base64Token></GetAccountByIdRequest></soap:Body></soap:Envelope>", 
		LAST);

	web_custom_request("GetAccountByIdNewRequest", 
		"URL={AOS_URL}/accountservice/ws/GetAccountByIdNewRequest", 
		"Method=POST", 
		"Resource=0", 
		"RecContentType=text/xml", 
		"Referer={AOS_URL}/", 
		"Snapshot=t49.inf", 
		"Mode=HTML", 
		"EncType=text/xml; charset=UTF-8", 
		"Body=<?xml version=\"1.0\" encoding=\"UTF-8\"?><soap:Envelope xmlns:soap=\"http://schemas.xmlsoap.org/soap/envelope/\" xmlns:xsi=\"http://www.w3.org/2001/XMLSchema-instance\" xmlns:xsd=\"http://www.w3.org/2001/XMLSchema\"><soap:Body><GetAccountByIdNewRequest xmlns=\"com.advantage.online.store.accountservice\"><accountId>{userId}</accountId><base64Token>Basic {t_authorization}</base64Token></GetAccountByIdNewRequest></soap:Body></soap:Envelope>", 
		LAST);
	
	web_add_header("Authorization",
		"Basic {t_authorization}");
	
	web_reg_find("Text=productsInCart", 
		LAST);

	web_url("userId", 
		"URL={AOS_URL}/order/api/v1/carts/{userId}", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer={AOS_URL}/", 
		"Snapshot=t50.inf", 
		"Mode=HTML", 
		LAST);

/*Correlation comment - Do not change!  Original value='14022025' Name ='transactionDate' Type ='Manual'*/
	web_reg_save_param_json(
		"ParamName=transactionDate",
		"QueryString=$.transactionDate",
		SEARCH_FILTERS,
		"Scope=Body",
		"IgnoreRedirections=No",
		LAST);

	web_custom_request("shippingcost",
		"URL={AOS_URL}/order/api/v1/shippingcost/",
		"Method=POST",
		"Resource=0",
		"RecContentType=application/json",
		"Referer={AOS_URL}/",
		"Snapshot=t51.inf",
		"Mode=HTML",
		"EncType=application/json;charset=UTF-8",
		"Body={\"seaddress\":{\"addressLine1\":\"address\",\"addressLine2\":\"\",\"city\":\"{cityName}\",\"country\":\"bs\",\"postalCode\":{zipcode},\"state\":\"{stateProvince}\"},\"secustomerName\":\"Admin User Mercury\",\"secustomerPhone\":\"{phoneNumber}\",\"senumberOfProducts\":1,\"setransactionType\":\"SHIPPING_COST\",\"sessionId\":\"{sessionId}\"}",
		LAST);

/*Correlation comment - Do not change!  Original value='98b6b0b5fdfd69bd379adaf14caf9fb77946b4ff' Name ='safePayPassword' Type ='Manual'*/
	web_reg_save_param_xpath(
		"ParamName=safePayPassword",
		"QueryString=/SOAP-ENV:Envelope/SOAP-ENV:Body/ns2:PaymentPreferences/ns2:preference/ns2:safePayPassword/text()",
		SEARCH_FILTERS,
		"Scope=Body",
		"IgnoreRedirections=No",
		LAST);

	web_custom_request("GetAccountPaymentPreferencesRequest", 
		"URL={AOS_URL}/accountservice/ws/GetAccountPaymentPreferencesRequest", 
		"Method=POST", 
		"Resource=0", 
		"RecContentType=text/xml", 
		"Referer={AOS_URL}/", 
		"Snapshot=t52.inf", 
		"Mode=HTML", 
		"EncType=text/xml; charset=UTF-8", 
		"Body=<?xml version=\"1.0\" encoding=\"UTF-8\"?><soap:Envelope xmlns:soap=\"http://schemas.xmlsoap.org/soap/envelope/\" xmlns:xsi=\"http://www.w3.org/2001/XMLSchema-instance\" xmlns:xsd=\"http://www.w3.org/2001/XMLSchema\"><soap:Body><GetAccountPaymentPreferencesRequest xmlns=\"com.advantage.online.store.accountservice\"><accountId>{userId}</accountId><base64Token>Basic {t_authorization}</base64Token></GetAccountPaymentPreferencesRequest></soap:Body></soap:Envelope>", 
		LAST);

	web_url("orderPayment-page.html", 
		"URL={AOS_URL}/app/order/views/orderPayment-page.html", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer={AOS_URL}/", 
		"Snapshot=t53.inf", 
		"Mode=HTML", 
		LAST);

	web_custom_request("GetCountriesRequest", 
		"URL={AOS_URL}/accountservice/ws/GetCountriesRequest", 
		"Method=POST", 
		"Resource=0", 
		"RecContentType=text/xml", 
		"Referer={AOS_URL}/", 
		"Snapshot=t54.inf", 
		"Mode=HTML", 
		"EncType=text/xml; charset=UTF-8", 
		"Body=<?xml version=\"1.0\" encoding=\"UTF-8\"?><soap:Envelope xmlns:soap=\"http://schemas.xmlsoap.org/soap/envelope/\" xmlns:xsi=\"http://www.w3.org/2001/XMLSchema-instance\" xmlns:xsd=\"http://www.w3.org/2001/XMLSchema\"><soap:Body><GetCountriesRequest xmlns=\"com.advantage.online.store.accountservice\"></GetCountriesRequest></soap:Body></soap:Envelope>", 
		LAST);

lr_end_transaction("AOS-Web-S04-06 Checkout",LR_AUTO);

	lr_think_time(10);


	web_reg_find("Text=SafePay data updated successfully", 
		LAST);
	
lr_start_transaction("AOS-Web-S04-07 Order Payment Next and Pay Now");

	web_custom_request("UpdateSafePayMethodRequest",
		"URL={AOS_URL}/accountservice/ws/UpdateSafePayMethodRequest",
		"Method=POST",
		"Resource=0",
		"RecContentType=text/xml",
		"Referer={AOS_URL}/",
		"Snapshot=t55.inf",
		"Mode=HTML",
		"EncType=text/xml; charset=UTF-8",
		"Body=<?xml version=\"1.0\" encoding=\"UTF-8\"?><soap:Envelope xmlns:soap=\"http://schemas.xmlsoap.org/soap/envelope/\" xmlns:xsi=\"http://www.w3.org/2001/XMLSchema-instance\" xmlns:xsd=\"http://www.w3.org/2001/XMLSchema\"><soap:Body><UpdateSafePayMethodRequest xmlns=\"com.advantage.online.store.accountservice\"><userId>{userId}</userId><safePayUsername>{loginUser}</safePayUsername><safePayPassword>98b6b0b5fdfd</safePayPassword><referenceId>1234567890</referenceId><base64Token>Basic {t_authorization}</base64Token></UpdateSafePayMethodRequest></soap:Body></soap:Envelope>",
		LAST);

	web_add_header("Authorization",
		"Basic {t_authorization}");
		
	web_reg_find("Text=success\":true,\"code\":\"Ok\",\"reason\":\"order completed successfully\",\"orderNumber", 
		LAST);
		
	web_custom_request("userId",
		"URL={AOS_URL}/order/api/v1/orders/users/{userId}",
		"Method=POST",
		"Resource=0",
		"RecContentType=application/json",
		"Referer={AOS_URL}/",
		"Snapshot=t56.inf",
		"Mode=HTML",
		"EncType=application/json",
		"Body={\"orderPaymentInformation\":{\"Transaction_AccountNumber\":\"843200971\",\"Transaction_Currency\":\"USD\",\"Transaction_CustomerPhone\":\"{phoneNumber}\",\"Transaction_MasterCredit_CVVNumber\":123,\"Transaction_MasterCredit_CardNumber\":\"4886123443211234\",\"Transaction_MasterCredit_CustomerName\":1234,\"Transaction_MasterCredit_ExpirationDate\":\"122034\",\"Transaction_PaymentMethod\":\"SafePay\",\"Transaction_ReferenceNumber\":0,\"Transaction_SafePay_Password\":\"{safePayPassword}\",\"Transaction_SafePay_UserName\":\"{loginUser}\",\"Transaction_TransactionDate\":\"{transactionDate}\",\"Transaction_Type\":\"PAYMENT\"},\"orderShippingInformation\":{\"Shipping_Address_Address\":\"address\",\"Shipping_Address_City\":\"{cityName}\",\"Shipping_Address_CountryCode\":10,\"Shipping_Address_CustomerName\":\"Admin User Mercury\",\"Shipping_Address_CustomerPhone\":\"{phoneNumber}\",\"Shipping_Address_PostalCode\":{zipcode},\"Shipping_Address_State\":\"{stateProvince}\",\"Shippi"
		"ng_Cost\":44.99,\"Shipping_NumberOfProducts\":1,\"Shipping_TrackingNumber\":0},\"purchasedProducts\":[{\"hexColor\":\"{color}\",\"productId\":{randomProductId},\"quantity\":1,\"hasWarranty\":false}]}",
		LAST);
		
	web_add_header("Authorization",
		"Basic {t_authorization}");
		
	web_reg_find("Text=productsInCart", 
		LAST);

	web_custom_request("userId", 
		"URL={AOS_URL}/order/api/v1/carts/{userId}", 
		"Method=DELETE", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer={AOS_URL}/", 
		"Snapshot=t57.inf", 
		"Mode=HTML", 
		LAST);

lr_end_transaction("AOS-Web-S04-07 Order Payment Next and Pay Now",LR_AUTO);

	lr_think_time(10);
	
	
	web_reg_find("Text=Logout Successful", 
		LAST);

lr_start_transaction("AOS-Web-S04-08 Sign Out");

	web_custom_request("AccountLogoutRequest", 
		"URL={AOS_URL}/accountservice/ws/AccountLogoutRequest", 
		"Method=POST", 
		"Resource=0", 
		"RecContentType=text/xml", 
		"Referer={AOS_URL}/", 
		"Snapshot=t58.inf", 
		"Mode=HTML", 
		"EncType=text/xml; charset=UTF-8", 
		"Body=<?xml version=\"1.0\" encoding=\"UTF-8\"?><soap:Envelope xmlns:soap=\"http://schemas.xmlsoap.org/soap/envelope/\" xmlns:xsi=\"http://www.w3.org/2001/XMLSchema-instance\" xmlns:xsd=\"http://www.w3.org/2001/XMLSchema\"><soap:Body><AccountLogoutRequest xmlns=\"com.advantage.online.store.accountservice\"><loginUser>{userId}</loginUser><base64Token>Basic {t_authorization}</base64Token></AccountLogoutRequest></soap:Body></soap:Envelope>", 
		LAST);

lr_end_transaction("AOS-Web-S04-08 Sign Out",LR_AUTO);

	lr_think_time(10);

	return 0;
}