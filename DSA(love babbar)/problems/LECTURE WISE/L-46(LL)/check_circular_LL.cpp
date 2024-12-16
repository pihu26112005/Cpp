/*
approach 1- ek temp node pointer bnaye , aur usko age bdae jab tak vapis head / null inme se koi nhi aya , fir check kre 
while(temp!=NULL && temp!=head)
{
    temp=temp.next;
}
if(temp == null){simply ll hogi}
else{circular hogi}

// TC - o(n) ,, SC - O(n)
*/