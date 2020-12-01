# 36. Accept the measure (angles) of a triangle and display
# the type of triangle. (eg. acute, right, obtuse)


read -p "Enter Angle: " angle

if [[ $angle -ge 0 && $angle -lt 90 ]]; then
    echo "Acute Angle"
elif [ $angle -eq 90 ]; then
    echo "Right Angle"
elif [[ $angle -ge 91 && $angle -le 180 ]]; then
    echo "Obtuse Angle"
else
    echo "Incorrect Input"
fi
