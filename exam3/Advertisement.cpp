#include "Advertisement.h"

using namespace std;

Advertisement::Advertisement(void) : 
	title(""), seller_email(""),
	body(""), number(-1) {}

Advertisement::Advertisement (string title, string seller_email, 
                              string body, Date start, Date close,
							  int quantity) :
	title(title), seller_email(seller_email),
	body(body), start(start), close(close),
	quantity(quantity), number(-1) {}

Advertisement::Advertisement (const Advertisement &a) : 
	title(a.title), seller_email(a.seller_email),
	body(a.body), start(a.start), 
	close(a.close), bids(a.bids),
	quantity(a.quantity),
	number(a.number) {}

string Advertisement::getEmail() const {
  return seller_email;
}

string Advertisement::getTitle() const {
  return title;
}
 
string Advertisement::getBody() const {
  return body;
}

void Advertisement::setStart (const Date &start) {
  this->start = start;
}

void Advertisement::setClose (const Date &close) {
  this->close = close;
}

void Advertisement::setTitle (string title) {
  this->title = title;
}

void Advertisement::setEmail (string email) {
  this->seller_email = email;
}

void Advertisement::setQuantity (int quantity) {
  this->quantity = quantity;
}

void Advertisement::setBody (string body) {
  this->body = body;
}

void Advertisement::setNumber (int number) {
  this->number = number;
}

Date Advertisement::getStart () const {
  return start;
}


Date Advertisement::getClose () const {
  return close;
}

int Advertisement::getNumber() const {
  return number;
}

int Advertisement::getQuantity() const {
  return quantity;
}

priority_queue<Bid>& Advertisement::getBids() {
	return bids;
}

vector<Bid> Advertisement::getTopDutchBids () const {

  priority_queue<Bid> scratchHeap = bids;
  vector<Bid> topBids;

  for (int itemsLeft=quantity; 
       (0 != itemsLeft) && (0 != scratchHeap.size());
       /* decrement by quantity of bid */ ) {
    Bid top = scratchHeap.top();
    scratchHeap.pop();
    topBids.push_back(top);

    if (itemsLeft <= top.getQuantity()) 
      break;
    else 
      itemsLeft -= top.getQuantity();
    
  }

  return topBids;

}

bool Advertisement::operator==(const Advertisement& rhs) const {
	if (this->getNumber() == rhs.getNumber()) {
		return true;
	}
	else {
		return false;
	}
}

istream &operator>>(istream &stream, Advertisement &a) {

  char line[80];
  string name;

  stream.getline(line, 80);
  a.setTitle(line);

  stream.getline(line, 80);
  a.setEmail(line);

  stream.getline(line, 80);
  a.setQuantity(atoi(line));

  Date in;
  stream >> in;
  a.setStart(in);

  stream >> in;
  a.setClose(in);

  stream.getline(line, 80);
  a.setBody(line);

  return stream;
}
