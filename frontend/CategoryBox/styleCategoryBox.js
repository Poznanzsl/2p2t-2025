import { StyleSheet } from "react-native"
import { Colors } from "../assets/cssVariables"

export default StyleSheet.create({
    box:{
        width: 150,
        height:150,
        borderRadius:'20%',
        backgroundColor:Colors.lightGreen,

        padding:'4%',
        margin:'7%',

        display:'flex',
        alignItems:'center',

        borderColor:Colors.darkGreen,
        borderWidth:5,

    },
    text: {
        fontSize:20,
        marginTop:'10%',
        fontWeight:'500',
        color:Colors.yellow,
    },
    emoji:{
        fontSize:50,
    }
})