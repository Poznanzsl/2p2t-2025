import { StyleSheet } from "react-native"
import { Colors } from "../assets/cssVariables"

export default StyleSheet.create({

    box :{
        width :350,
        height: 200,
        backgroundColor:Colors.lightGreen,
        borderRadius:5,
        display:'flex',
        flexDirection:'row',
        marginBottom:'5%',
        margin:"auto",
        alignItems: 'center',
    },
    name:{
        fontSize:35,
        color:Colors.yellow,
        fontWeight:'600',
        marginLeft:'4%',
        width: 330,
        textAlign: 'center',
    }
})