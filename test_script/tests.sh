GREEN="\033[0;32m"
  RED="\033[0;31m"
RESET="\033[0m"

FILE="so_long"

if [ ! -f ${FILE} ]
then
	make fclean
	make re
fi

# Checking for no input
NO_INPUT_ERROR=$(./so_long  | grep "Not enough arguments, try again" | wc -l)

if [ ${NO_INPUT_ERROR} -ge 1 ]
then
	echo "Checking for no input: $GREEN [OK] $RESET"
else
	echo "Checking for no input: $RED [KO] $RESET"
fi

# Checking for maps that do not exist
NO_MAP="no_map"
NO_MAP_ERROR=$(./so_long $NO_MAP | grep "Choose a correct map!" | wc -l)

if [ ${NO_MAP_ERROR} -ge 1 ]
then
	echo "Checking for invalid input: $GREEN [OK] $RESET"
else
	echo "Checking for invalid input: $RED [KO] $RESET"
fi

# Checking for invalid maps
INVALID_WALL_MAP="./maps/maps_invalid_map.ber"
INVALID_WALL_MAP_ERROR=$(./so_long $INVALID_WALL_MAP | grep "Invalid walls, map is not fully covered with walls!" | wc -l)

if [ ${INVALID_WALL_MAP_ERROR} -ge 1 ]
then
	echo "Checking for invalid walls: $GREEN [OK] $RESET"
else
	echo "Checking for invalid walls: $RED [KO] $RESET"
fi

# Checking for missing player (P)
MISSING_P="./maps/maps_missing_p.ber"
MISSING_P_ERROR=$(./so_long $MISSING_P | grep "Player is missing!" | wc -l)

if [ ${MISSING_P_ERROR} -ge 1 ]
then
	echo "Checking for missing player $GREEN [OK] $RESET"
else
	echo "Checking for missing player: $RED [KO] $RESET"
fi

# Checking for missing exit (E)
MISSING_E="./maps/maps_missing_e.ber"
MISSING_E_ERROR=$(./so_long $MISSING_E | grep "Player is missing!" | wc -l)

if [ ${MISSING_E_ERROR} -ge 1 ]
then
	echo "Checking for missing exit: $GREEN [OK] $RESET"
else
	echo "Checking for missing exit: $RED [KO] $RESET"
fi