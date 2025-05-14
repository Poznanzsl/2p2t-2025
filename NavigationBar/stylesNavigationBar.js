import { StyleSheet } from "react-native";

export default StyleSheet.create({

    bar: {
        width: '100%',
        height: '10%',
        backgroundColor:'white',
        boxShadow:'5 2 5 gray',
        position:'absolute',
        bottom:0,
        justifyContent: 'center',
        display: 'flex',
        flexDirection: 'row',

        // iOS shadow
        shadowColor: '#000',
        shadowOffset: { width: 0, height: -5 },
        shadowOpacity: 0.25,
        shadowRadius: 5,
        
        // Android shadow
        elevation: 10,

    },

    button:{
        width: 50,
        height:50,
        color:'white',

        margin: 10,
        marginLeft:30,
        marginRight:30,

        display: 'flex',
        justifyContent:'center',
        alignItems:'center',

    },

    img:{
        width:40,
        height:40,
    },

    buttonText: {
        color: 'white',
        fontSize: 18,

    },

    text:{
        margin:1,
        fontSize:10,
        color:'black',
        position: 'absolute',
        bottom:0,
    },

    buttonAndTextBox:{
        display:'flex',
        alignItems:'center',
    }

    

})