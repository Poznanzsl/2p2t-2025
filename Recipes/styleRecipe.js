import { StyleSheet } from "react-native"

export default StyleSheet.create({

    box :{
        width : '80%',
        height:120,
        backgroundColor:'lightgray',
        borderRadius:5,
        display:'flex',
        flexDirection:'row',
        margin:10,
        marginLeft:35,
    },

    time:{
        fontSize:15,
        color:'black',
        position:'absolute',
        top:35,
        left:5,
    },
    name:{
        fontSize:15,
        color:'black',
        fontWeight:'900',

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