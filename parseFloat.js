//Jay Tayade
//Weebly Coding Challenge
function weeblyFloat(str)
{
	var res = str.split(".");
	var placeVal = 1/10;
	var result = 0;
	if(res.length == 2)
	{
  		//If there are digits after the decimal, add them and 
  		//divide the place val by 10 eachtime
  		for(i=0; i < res[1].length; i++)
  		{
    		result = result + (res[1][i] - '0') * placeVal;
    		placeVal = placeVal/10;
    		//console.log(result);
  		}
	}
	placeVal = 1;
	for(i=res[0].length-1; i >= 0; i--)
	{
  		//For the characters in front of the decimal point, add them to the result and multiply placeval by 10 each time
  		result = result + (res[0][i] - '0') * placeVal;
  		placeVal = placeVal*10;
  		//console.log(result);
	}
	return result;
}

var str = "132.23";
result = weeblyFloat(str);
console.log(result);
//To test the resulting type
console.log(result + 2);

