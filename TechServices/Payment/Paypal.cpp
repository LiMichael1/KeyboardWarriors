#include "Paypal.hpp"

Paypal::~Paypal()
{
	log.close();
}

bool Paypal::CreatePayment() {
		cout << "Payment Created by Paypal!" << endl;
		log << current_time << endl << "Payment Created by Paypal!" << endl;
		return true;
}

bool Paypal::SetPaymentInfo() {
		cout << "Payment Info Set by Paypal!" << endl;
		return true;
}

bool Paypal::GetPaymentInfo() {
	cout << "Payment Details gotten by Paypal!" << endl;
	return true;
}

bool Paypal::EditPaymentInfo() {
	cout << "Go to Edit Payment Info by Paypal!" << endl;
	return true;
}

bool Paypal::AuthorizePaymentInfo() {
	cout << "Authorized Payment Info by Paypal!" << endl;
	return true;
}

string Paypal::CreateOrder(string purchaseItemID) {
	cout << "Order Created by Paypal!" << endl;
	return "OrderIDTest";
}

bool Paypal::UpdateOrder(string orderID) {
	cout << "Updated Order by Paypal!" << endl;
	return true;
}

bool Paypal::GetOrderInfo(string orderID) {
	cout << "Order Details gotten by Paypal!" << endl;
	return true;
}

bool Paypal::AuthorizePaymentForOrder(string orderID) {
	cout << "Payment Authorized for Order by Paypal!" << endl;
	return true;
}

bool Paypal::CapturePaymentForOrder(string orderID) {
	cout << "Payment Made, Order Submitted by Paypal!" << endl;
	return true;
}
