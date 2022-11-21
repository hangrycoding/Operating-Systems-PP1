#!/bin/bash

temph=`date +"%H"` # set a format with 24 hours(0-23)
dat=`date +"%A %d in %B of %Y (%r)"`

if [ $temph -lt 12 ]
then
    msg="Good Morning $LOGNAME, Have nice day!"
elif [ $temph -ge 12 -a $temph -le 16 ]
then
    msg="Good Afternoon $LOGNAME"
elif [ $temph -gt 16 -a $temph -le 20 ]
then
    msg="Good Evening $LOGNAME"
else
    msg="Hello $LOGNAME!" # Just display hello if the time is not matched with anything above
fi


greeting="$msg\nThis is $dat" # save to variable


# Output to file called 'greetingmsg' (destructive writing)
echo -e ${greeting} > greetingmsg
echo -e ${greeting}
