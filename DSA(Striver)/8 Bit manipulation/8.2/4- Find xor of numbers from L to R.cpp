 int f(int n){
         
        if(n%4 == 0){
            return n;
        }else if(n%4 == 1){
            return 1;
        }else if(n%4 == 2){
            return n+1;
        }
        return 0;
    }
  
    int findXOR(int l, int r) {
       
       return f(l-1) ^ f(r);
    }