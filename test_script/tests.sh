GREEN="\033[0;32m"
  RED="\033[0;31m"
RESET="\033[0m"
  MAP="/maps/map-invalid-parameter.ber"
ERROR=$(./so_long $MAP | grep "Error" | wc -l)

if [ ${ERROR} -ge 1 ]
then
	echo -e "Check invalid parameter: $GREEN [OK] $RESET"
else
	echo -e "Check invalid parameter: $RED [KO] $RESET"
fi