###################################################################
  # File Name: 40-here.sh
  # Author: fly
  # Mail: XXXXXXXX@icode.com
  # Created Time: Fri 02 Jun 2017 02:04:09 PM CST
###################################################################
#!/bin/bash

ed a_text_file << !Funky!
3
d
.,\$s/is/was/
w
q
!Funky!

exit 0
