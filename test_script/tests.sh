GREEN="\033[0;32m"
  RED="\033[0;31m"
RESET="\033[0m"

# Checking for maps that do not exist

NO_MAP="no_map"
NO_MAP_ERROR=$(./so_long $NO_MAP | grep "Choose a correct map!" | wc -l)

echo "Check error management for invalid input:"
if [ ${NO_MAP_ERROR} -ge 0 ]
then
	echo "Checking for invalid input: $GREEN [OK] $RESET"
else
	echo "Checking for invalid input: $RED [KO] $RESET"
fi
