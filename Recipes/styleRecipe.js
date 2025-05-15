import { StyleSheet } from "react-native"
import { Colors } from "../assets/cssVariables"

export default StyleSheet.create({

    box :{
        width :350,
        height:200,
        backgroundColor:Colors.lightGreen,
        borderRadius:5,
        display:'flex',
        flexDirection:'row',
        marginBottom:'5%',
        marginLeft:"3%",
    },

    time:{
        fontSize:15,
        color: 'black',
        position:'absolute',
        fontWeight:'300',
        top:35,
        left:5,
    },
    name:{
        fontSize:15,
        color:Colors.yellow,
        fontWeight:'600',

        position:'absolute',
        left:50,
        top:5,
        //ToDo: ladne centrowanie sie tego napisu
    },
    img:{
        width:90,
        height:90,
        

        position:'absolute',
        right:3,
        margin:12,
        top:2,

        borderColor:'black',
        borderWidth:1,
        borderRadius:0,
    }
})