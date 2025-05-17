import { StyleSheet } from "react-native";
import { Colors } from "../assets/cssVariables"; 

export default StyleSheet.create({

    bar: {
        width: '100%',
        height: '10%',
        backgroundColor: Colors.darkGreen,

        position:'absolute',
        bottom:0,
        justifyContent: 'center',
        display: 'flex',
        flexDirection: 'row',

    },

    button:{
        width: 100,
        height: 100 ,
        color:'white',

        display: 'flex',
        justifyContent:'center',
        alignItems:'center',
    },

    img:{
        width:40,
        height:40,
    },
    text:{
        fontSize:12,
        color:Colors.yellow, 
        position: 'absolute',
        bottom:0,
    },

    buttonAndTextBox:{
        display:'flex',
        alignItems:'center',
        justifyContent:'center',
        marginTop:"-3%",
        height:'100%',
    }

    

})