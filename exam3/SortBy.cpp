#include "SortBy.h"

using namespace std;

SortBy::SortBy(string keyField) : keyField(keyField) {}  

bool SortBy::operator()(Advertisement *a1, Advertisement *a2) {
    
    if (keyField == "email") {
      return (a1->getEmail() < a2->getEmail());
    }
    
    if (keyField == "start") {
      return (a1->getStart() < a2->getStart());
    }
    
    if (keyField == "close") {
      return (a1->getClose() < a2->getClose());
    }

    if (keyField == "quantity") {
      return (a1->getQuantity() < a2->getQuantity());
    }

    if (keyField == "highest" || keyField == "lowest") {
      
      float amount1 = 0;
      float amount2 = 0;
      
      if (a1->getBids().size() > 0) {
         amount1 = a1->getBids().top().getAmount();
      }
      if (a2->getBids().size() > 0) {
         amount2 = a2->getBids().top().getAmount();
      }
        
      return ((keyField == "highest") ? (amount1 > amount2) : (amount1 < amount2));
    }

    return false;
}

